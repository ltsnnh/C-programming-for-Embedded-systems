#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "HAL.h"
#include "FAT.h"

/********************************************************************
 * Definitions
********************************************************************/
/* __attribute__((packed)), which tells the compiler not to insert padding. */
#if (__GNU__)
#define FAT_PACK __attribute__((packed))
#else
#define FAT_PACK
#endif

/**
 * @defgroup    Format 32-byte directory entries, in directory table.
 *
 */
#define ENTRY_SHORT_FILE_NAME_OFFSET        0x00u
#define ENTRY_SHORT_FILE_NAME_LENGTH        8
#define ENTRY_SHORT_EXTENSION_OFFSET        0x08u
#define ENTRY_SHORT_EXTENSION_LENGTH        3
#define ENTRY_FILE_ATTRIBUTES_OFFSET        0x0Bu
#define ENTRY_USER_ATTRIBUTES_OFFSET        0x0Cu
#define ENTRY_CREATE_TIME_MS_OFFSET         0x0Du
#define ENTRY_CREATE_TIME_OFFSET            0x0Eu
#define ENTRY_CREATE_DATE_OFFSET            0x10u
#define ENTRY_LAST_ACCESS_DATE_OFFSET       0x12u
#define ENTRY_ACCESS_RIGHT_OFFSET           0x14u
#define ENTRY_MODIFIED_TIME_OFFSET          0x16u
#define ENTRY_MODIFIED_DATE_OFFSET          0x18u
#define ENTRY_FIRST_CLUSTER_OFFSET          0x1Au
#define ENTRY_FILE_SIZE_OFFSET              0x1Cu

/**
 * @defgroup    Special values of the first byte in SFN field (in Directory entry).
 *
 */
#define FIRST_BYTE_SFN_END_MARKED_ENTRY     0x00u
#define FIRST_BYTE_SFN_ACTUALLY_0XE5        0x05u
#define FIRST_BYTE_SFN_DOT_ENTRY            0x2Eu
#define FIRST_BYTE_SFN_PREVIOUSLY_ERASED    0xE5u

/**
 * @defgroup    File attributes bit mask (in Directory entry).
 *
 */
#define BITMASK_READ_ONLY                   0x01u
#define BITMASK_HIDDEN                      0x02u
#define BITMASK_SYSTEM                      0x04u
#define BITMASK_VOLUME_LABEL                0x08u
#define BITMASK_SUBDIRECTORY                0x10u
#define BITMASK_ARCHIVE                     0x20u
#define BITMASK_DEVICE                      0x40u
#define BITMASK_RESERVE                     0x80u

/**
 * @defgroup    Cluster limits type of FAT.
 *
 */
#define CLUSTER_LIMIT_FAT12                 4084
#define CLUSTER_LIMIT_FAT16                 65524
#define CLUSTER_LIMIT_FAT32                 268435444

/**
 * @defgroup    More description of FAT file system.
 *
 */
#define START_CLUSTER_NUM                   2
#define SIZE_OF_ENTRY                       32

/**
 * @define  Calculator in little-endian.
 *
 */
#define FAT_READ_UINT16(buff)           (((uint16_t)((buff)[1]) << 8) | ((buff)[0]))
#define FAT_READ_UINT32(buff)           (((uint32_t)((buff)[3]) << 24) | ((uint32_t)((buff)[2]) << 16) | ((uint32_t)((buff)[1]) << 8) | ((buff)[0]))
#define FAT_READ_FIELD_3BYTES(buff)     ((((uint32_t)((buff)[2]) << 16) | ((uint32_t)((buff)[1]) << 8) | ((buff)[0])) & 0x00FFFFFF)

/**
 * @define  Calculator time-date (in Directory entry).
 *
 */
#define FAT_READ_MINUTE(time)   ((uint8_t)(((time) >> 5) & 0x003F))
#define FAT_READ_HOUR(time)     ((uint8_t)((time)  >> 11))
#define FAT_READ_DAY(date)      ((uint8_t)((date) & 0x001F))
#define FAT_READ_MONTH(date)    ((uint8_t)(((date) >> 5) & 0x000F))
#define FAT_READ_YEAR(date)     (((date) >> 9) + 1980)

/**
 * @define  BIOS Parameter Block - DOS 3.31 BPB (in BOOT sector).
 *
 */
typedef struct
{
    uint8_t bytes_per_sector[2];            /* 0x00B */
    uint8_t sectors_per_cluster;            /* 0x00D */
    uint8_t count_reserved_sector[2];       /* 0x00E */
    uint8_t number_of_fat_table;            /* 0x010 */
    uint8_t max_root_entries[2];            /* 0x011 */
    uint8_t total_sectors[2];               /* 0x013 */
    uint8_t media_descriptor;               /* 0x015 */
    uint8_t sectors_per_fat_table[2];       /* 0x016 */
    /* DOS 3.31 BPB */
    uint8_t physical_sectors_per_track[2];  /* 0x018 */
    uint8_t number_of_heads_for_disks[2];   /* 0x01A*/
    uint8_t count_of_hidden_sectors[4];     /* 0x01C */
    uint8_t bigger_total_sectors[4];        /* 0x020 */
}FAT_PACK fat_bios_parameter_block_struct_t;/* lenghth = 25 bytes */

/**
 * @define  Extended BIOS Parameter Block (in BOOT sector).
 *
 */
typedef struct
{
    uint8_t physical_drive_number;          /* 0x024 */
    uint8_t reserved;                       /* 0x025 */
    uint8_t extended_boot_signature;        /* 0x026 */
    uint8_t volume_id[4];                   /* 0x027 */
    uint8_t partition_volume_label[11];     /* 0x02B */
    uint8_t file_system_type[8];            /* 0x036 */

    uint8_t specific_boot_info[447];
}FAT_PACK fat_extended_bpb_struct_t;        /* length = 26 + 447 bytes */

/**
 * @define  FAT32 Extended BIOS Parameter Block (in BOOT sector).
 *
 */
typedef struct
{
    uint8_t sectors_per_fat_table[4];       /* 0x024 */
    uint8_t drive_description[2];           /* 0x028 */
    uint8_t version[2];                     /* 0x02A */
    uint8_t root_dir_start_cluster[4];      /* 0x02C */
    uint8_t sector_number_fs_info[2];       /* 0x030 */
    uint8_t sector_copy_fats_sector[2];     /* 0x032 */
    uint8_t reserved[12];                   /* 0x034 */
    uint8_t physical_drive_number;          /* 0x040 */
    uint8_t for_various_purposes;           /* 0x041 */
    uint8_t extended_boot_signature;        /* 0x042 */
    uint8_t volume_id[4];                   /* 0x043 */
    uint8_t volume_label[11];               /* 0x047 */
    uint8_t file_system_type[8];            /* 0x052 */

    uint8_t specific_boot_info[419];
}FAT_PACK fat_fat32_extended_bpb_struct_t;  /* length = 54 + 419 bytes */

/**
 * @define  First 512 byte indicate FATFS information description (in BOOT sector).
 *
 */
typedef struct
{
    uint8_t jump_instruction[3];            /* 0x000 */
    uint8_t oem_name[8];                    /* 0x003 */
    fat_bios_parameter_block_struct_t bios;
    fat_fat32_extended_bpb_struct_t fat32_bpb;
    uint8_t physical_drive_number;          /* 0x1FD */
    uint8_t boot_sector_signature[2];       /* 0x1FE */
}FAT_PACK fat_boot_sector_struct_t;         /* lenghth = 512 bytes */

/**
 * @define  Last cluster (EOC) (in FAT table).
 *
 */
typedef enum
{
    eoc_fat12 = 0xFF8u,
    eoc_fat16 = 0xFFF8u,
    eoc_fat32 = 0x0FFFFFF8u
}end_of_chain_fat_t;

/**
 * @define  Type of entry.
 *
 */
typedef enum
{
    normal_entry = 0,
    LFN_entry = 1,
    deleted_entry = 2,
    hidden_entry = 3,
    EOC_entry = 4
}fat_entry_type_t;

/**
 * @define  Type of cluster.
 *
 */
typedef enum                        /* if this value occurs in cluster chains */
{                                   /* file system implementations should treat this like an */
    free_cluster = 0,               /* EOC */
    internal_purpose_cluster = 1,   /* EOC */
    data_cluster = 2,               /* normal data clusters */
    reserved_cluster = 3,           /* normal data clusters */
    not_used_cluster = 4,           /* normal data clusters */
    bad_sector_cluster = 5,         /* normal data clusters */
    eoc_cluster = 6                 /* EOC */
}fat_cluster_type_t;

/**
 * @define  Important info FAT FILE SYSTEM for calculate purpose.
 *
 */
typedef struct
{
    uint16_t bytes_per_sector;
    uint8_t sectors_per_cluster;
    uint16_t count_reserved_sector;
    uint8_t number_of_fat_table;
    uint16_t max_root_entries;          /* for FAT12/FAT16 */
    uint32_t total_sectors;
    uint32_t sectors_per_fat_table;
    uint16_t size_of_root;              /* for FAT12/FAT16 */
    uint32_t root_dir_start_cluster;    /* for FAT32 */
    end_of_chain_fat_t eoc_fat;         /* Indicate type of FAT file system */
    uint32_t fat_offset;
    uint32_t root_offset;
    uint32_t data_offset;
}fat_info_struct_t;

/********************************************************************
 * Prototypes
********************************************************************/
static fat_error_code_t fat_creat_entry_list(uint32_t first_cluster);
static fat_entry_type_t fat_parse_entry(uint8_t *buff);
static void fat_update_entry_list(fat_entry_struct_t *entry);
static void fat_free_entry_list(void);
static fat_cluster_type_t fat_check_cluster_type(uint32_t cluster_index);
static uint32_t fat_get_next_cluster(uint32_t current_cluster);
static void fat_myMemCpy(uint8_t *dest, uint8_t *src, int32_t n);

/********************************************************************
 * Variables
********************************************************************/
static fat_info_struct_t s_fat_info;
static fat_entry_struct_t *sp_fat_entry_head = NULL; /* HEAD */

/********************************************************************
 * Code
********************************************************************/
/**
 * @brief   Initialize FAT file system parameters, open STREAM to FILE
 *
 * @param   file name, entry list head
 * @return  error code
 */
fat_error_code_t fat_init(int8_t *file_name, fat_entry_struct_t **entry_head)
{
    fat_error_code_t retVal = error_code_success;
    fat_boot_sector_struct_t boot_sector;
    int32_t num_bytes_read = 0;
    uint16_t total_cluster = 0;

    if(kmc_open_file(file_name))
    {
        /* Read first 512 bytes in BOOT sector */
        num_bytes_read = kmc_read_sector(0, (uint8_t*)&boot_sector);
        if(num_bytes_read == 512)
        {
            s_fat_info.bytes_per_sector = FAT_READ_UINT16(boot_sector.bios.bytes_per_sector);
            s_fat_info.sectors_per_cluster = boot_sector.bios.sectors_per_cluster;
            s_fat_info.count_reserved_sector = FAT_READ_UINT16(boot_sector.bios.count_reserved_sector);
            s_fat_info.number_of_fat_table = boot_sector.bios.number_of_fat_table;
            s_fat_info.max_root_entries = FAT_READ_UINT16(boot_sector.bios.max_root_entries);
            s_fat_info.fat_offset = s_fat_info.count_reserved_sector;
            if(s_fat_info.max_root_entries == 0)    /* Indicate FAT32 file system */
            {
                s_fat_info.eoc_fat = eoc_fat32;
                s_fat_info.root_dir_start_cluster = FAT_READ_UINT32(boot_sector.fat32_bpb.root_dir_start_cluster);
                s_fat_info.total_sectors = FAT_READ_UINT32(boot_sector.bios.bigger_total_sectors);
                s_fat_info.sectors_per_fat_table = FAT_READ_UINT32(boot_sector.fat32_bpb.sectors_per_fat_table);
                s_fat_info.data_offset = s_fat_info.count_reserved_sector + s_fat_info.number_of_fat_table * s_fat_info.sectors_per_fat_table;
                retVal = fat_creat_entry_list(s_fat_info.root_dir_start_cluster);
            }
            else
            {
                s_fat_info.size_of_root = s_fat_info.max_root_entries * 32 / s_fat_info.bytes_per_sector;
                s_fat_info.total_sectors = FAT_READ_UINT16(boot_sector.bios.total_sectors);
                s_fat_info.sectors_per_fat_table = FAT_READ_UINT16(boot_sector.bios.sectors_per_fat_table);
                s_fat_info.root_offset = s_fat_info.count_reserved_sector + s_fat_info.number_of_fat_table * s_fat_info.sectors_per_fat_table;
                s_fat_info.data_offset = s_fat_info.root_offset + s_fat_info.size_of_root;
                total_cluster = (s_fat_info.total_sectors - s_fat_info.data_offset)/s_fat_info.sectors_per_cluster;
                if(total_cluster <= CLUSTER_LIMIT_FAT12)   /* Indicate FAT12 file system */
                {
                    s_fat_info.eoc_fat = eoc_fat12;
                }
                else if((total_cluster > CLUSTER_LIMIT_FAT12) && (total_cluster <= CLUSTER_LIMIT_FAT16))    /* Indicate FAT16 file system */
                {
                    s_fat_info.eoc_fat = eoc_fat16;
                }
                retVal = fat_creat_entry_list(0);   /* After parse parameters in BOOT, creat list files and folders in ROOT */
            }
            *entry_head = sp_fat_entry_head;
        }
        else
        {
            retVal = error_code_init_failed;    /* If read first 512 bytes is not success */
        }
    }
    else
    {
        retVal = error_code_init_failed;    /* If open FILE do not success */
    }

    return(retVal);
}

/**
 * @brief   Funtion read Directory
 *
 * @param   first cluster start Directory Table area, entry head give head of entry list
 * @return  error code
 */
fat_error_code_t fat_read_directory(uint32_t first_cluster, fat_entry_struct_t **entry_head)
{
    fat_error_code_t retVal = error_code_success;

    fat_free_entry_list();  /* free entry list of parent directory */
    retVal = fat_creat_entry_list(first_cluster);   /* create new entry list of current directory */

    if(error_code_success == retVal)
    {
        *entry_head = sp_fat_entry_head;
    }
    else
    {
        retVal = error_code_read_directory_failed;
    }

    return(retVal);
}

/**
 * @brief   Function read file
 *
 * @param   first cluster start file special area, buffer get read data, file size (in bytes)
 * @return  error code
 */
fat_error_code_t fat_read_file(uint32_t first_cluster, uint8_t *p_buff, uint32_t file_size)
{
    fat_error_code_t retVal = error_code_success;
    uint8_t *cluster_buff = NULL;
    int32_t bytes_read = 0;
    uint32_t byte_index = 0;

    cluster_buff = (uint8_t*)malloc(s_fat_info.sectors_per_cluster * s_fat_info.bytes_per_sector);
    do
    {
        bytes_read = kmc_read_multi_sector(s_fat_info.data_offset + (first_cluster - 2) * s_fat_info.sectors_per_cluster, s_fat_info.sectors_per_cluster, cluster_buff);
        if(bytes_read == s_fat_info.sectors_per_cluster * s_fat_info.bytes_per_sector)
        {
            fat_myMemCpy(p_buff, cluster_buff, bytes_read);
            byte_index += bytes_read;
        }
        else
        {
            retVal = error_code_read_file_failed;
        }
        if(eoc_cluster == fat_check_cluster_type(first_cluster))
        {
            retVal = error_code_success;
        }
        first_cluster = fat_get_next_cluster(first_cluster);
    }while((error_code_success == retVal) && (byte_index < file_size));
    free(cluster_buff);

    return(retVal);
}

/**
 * @brief   Function Deinit, free all entry list, close STREAM to FILE
 *
 * @param   void
 * @return  error code
 */
fat_error_code_t fat_deinit(void)
{
    fat_error_code_t retVal = error_code_success;

    if(kmc_close_file())
    {
        fat_free_entry_list();
    }
    else
    {
        retVal = error_code_deinit_failed;
    }

    return(retVal);
}

/**
 * @brief   Creat entry list includes info all of entry in current directory
 *
 * @param   first cluster
 * @return  error code
 */
static fat_error_code_t fat_creat_entry_list(uint32_t first_cluster)
{
    fat_error_code_t retVal = error_code_success;
    uint8_t *buff = NULL;
    uint16_t offset = 0;
    int32_t num_bytes_read = 0;
    uint32_t cluster_index = s_fat_info.root_dir_start_cluster;
    fat_entry_type_t entry_status = normal_entry;

    if(first_cluster == 0)
    {
        if(s_fat_info.eoc_fat == eoc_fat12 || s_fat_info.eoc_fat == eoc_fat16)
        {
            /* Read ROOT directory FAT12/FAT16 */
            buff = (uint8_t*)malloc(s_fat_info.size_of_root * s_fat_info.bytes_per_sector);
            num_bytes_read = kmc_read_multi_sector(s_fat_info.root_offset, s_fat_info.size_of_root, buff);
            if(num_bytes_read == s_fat_info.size_of_root * s_fat_info.bytes_per_sector)
            {
                for(offset = 0; (EOC_entry != entry_status) && (offset < num_bytes_read); offset += SIZE_OF_ENTRY)
                {
                    entry_status = fat_parse_entry(&buff[offset]);
                }
            }
            else
            {
                retVal = error_code_init_failed;
            }
            free(buff);
        }
        else if(s_fat_info.eoc_fat == eoc_fat32)    /* First cluster = 0 indicates return ROOT from 1 subdirectory in FAT32 file system */
        {
            buff = (uint8_t*)malloc(s_fat_info.sectors_per_cluster * s_fat_info.bytes_per_sector);
            while(EOC_entry != entry_status)
            {
                num_bytes_read = kmc_read_multi_sector(s_fat_info.data_offset + (cluster_index - START_CLUSTER_NUM) * s_fat_info.sectors_per_cluster, s_fat_info.sectors_per_cluster, buff);
                if(num_bytes_read == s_fat_info.sectors_per_cluster * s_fat_info.bytes_per_sector)
                {
                    for(offset = 0; (EOC_entry != entry_status) && (offset < num_bytes_read); offset += SIZE_OF_ENTRY)
                    {
                        entry_status = fat_parse_entry(&buff[offset]);
                    }
                    if(data_cluster != fat_check_cluster_type(cluster_index))
                    {
                        entry_status = EOC_entry;
                    }
                    else
                    {
                        cluster_index = fat_get_next_cluster(cluster_index);
                    }
                }
                else
                {
                    retVal = error_code_init_failed;
                }

            }
            free(buff);
        }
    }
    else if(data_cluster != fat_check_cluster_type(first_cluster))
    {
        retVal = error_code_init_failed;
    }
    else    /* Read normal cluster in DATA area */
    {
        buff = (uint8_t*)malloc(s_fat_info.sectors_per_cluster * s_fat_info.bytes_per_sector);
        while(EOC_entry != entry_status)
        {
            num_bytes_read = kmc_read_multi_sector(s_fat_info.data_offset + (first_cluster - START_CLUSTER_NUM) * s_fat_info.sectors_per_cluster, s_fat_info.sectors_per_cluster, buff);
            if(num_bytes_read == s_fat_info.sectors_per_cluster * s_fat_info.bytes_per_sector)
            {
                for(offset = 0; (EOC_entry != entry_status) && (offset < num_bytes_read); offset += SIZE_OF_ENTRY)
                {
                    entry_status = fat_parse_entry(&buff[offset]);
                }
                if(data_cluster != fat_check_cluster_type(first_cluster))
                {
                    entry_status = EOC_entry;
                }
                else
                {
                    first_cluster = fat_get_next_cluster(first_cluster);
                }
            }
            else
            {
                retVal = error_code_init_failed;
            }
        }
        free(buff);
    }

    return(retVal);
}

/**
 * @brief   Function parse entry by entry
 *
 * @param   buff is offset 32 bytes of entry
 * @return  entry type
 */
static fat_entry_type_t fat_parse_entry(uint8_t *buff)
{
    fat_entry_type_t retVal = normal_entry;
    fat_entry_struct_t *entry = NULL;
    static char file_name[256];
    static uint16_t LFN_len = 0;
    uint16_t time_binary;
    uint16_t date_binary;
    int8_t index = 0;

    if(0x0Fu == buff[ENTRY_FILE_ATTRIBUTES_OFFSET])
    {
        retVal = LFN_entry;
        if(0 != (buff[0] & 0x40))     /* last LFN entry: 010? ???? */
        {
            LFN_len = 0;
        }
        for(index = 0; index < 10; index += 2, LFN_len++)
        {
            file_name[LFN_len] = buff[0x01 + index];
        }
        for(index = 0; index < 12; index += 2, LFN_len++)
        {
            file_name[LFN_len] = buff[0x0E + index];
        }
        for(index = 0; index < 4; index += 2, LFN_len++)
        {
            file_name[LFN_len] = buff[0x1C + index];
        }
        /* remove padding spaces */
        while(file_name[LFN_len - 1] == ' ')
        {
            LFN_len--;
        }
        file_name[LFN_len] = '\0'; /* remove last space and add 'End of string' */
    }
    else if(0x00u == buff[ENTRY_SHORT_FILE_NAME_OFFSET])
    {
        retVal = EOC_entry;
    }
    else if(0xE5u == buff[ENTRY_SHORT_FILE_NAME_OFFSET])
    {
        retVal = deleted_entry;
    }
    else if(0 != (BITMASK_HIDDEN & buff[ENTRY_FILE_ATTRIBUTES_OFFSET]))
    {
        retVal = hidden_entry;
    }
    else
    {
        entry = (fat_entry_struct_t*)malloc(sizeof(fat_entry_struct_t));

        /* get file name */
        if(LFN_len > 0)
        {
            strcpy(entry->name, file_name);
            LFN_len = 0;
        }
        else
        {
            for(index = 0; index < ENTRY_SHORT_FILE_NAME_LENGTH; index++)
            {
                file_name[index] = buff[ENTRY_SHORT_FILE_NAME_OFFSET + index];
            }
            file_name[index] = '\0';
            strcpy(entry->name, file_name);
            for(index = 0; index < ENTRY_SHORT_EXTENSION_LENGTH; index++)
            {
                file_name[index] = buff[ENTRY_SHORT_EXTENSION_OFFSET + index];
            }
            file_name[index] = '\0';
            strcpy(entry->extension, file_name);
        }

        /* indicate subdir or file */
        if(0 != (BITMASK_SUBDIRECTORY & buff[ENTRY_FILE_ATTRIBUTES_OFFSET]))
        {
            entry->subdir = true;
        }
        else
        {
            entry->subdir = false;
        }

        /* get create date and time */
        time_binary = FAT_READ_UINT16(&buff[ENTRY_CREATE_TIME_OFFSET]);
        date_binary = FAT_READ_UINT16(&buff[ENTRY_CREATE_DATE_OFFSET]);
        entry->create_time.minute = FAT_READ_MINUTE(time_binary);
        entry->create_time.hour = FAT_READ_HOUR(time_binary);
        entry->create_time.day = FAT_READ_DAY(date_binary);
        entry->create_time.month = FAT_READ_MONTH(date_binary);
        entry->create_time.year = FAT_READ_YEAR(date_binary);

        /* get last modified date and time */
        time_binary = FAT_READ_UINT16(&buff[ENTRY_MODIFIED_TIME_OFFSET]);
        date_binary = FAT_READ_UINT16(&buff[ENTRY_MODIFIED_DATE_OFFSET]);
        entry->modified_time.minute = FAT_READ_MINUTE(time_binary);
        entry->modified_time.hour = FAT_READ_HOUR(time_binary);
        entry->modified_time.day = FAT_READ_DAY(date_binary);
        entry->modified_time.month = FAT_READ_MONTH(date_binary);
        entry->modified_time.year = FAT_READ_YEAR(date_binary);

        /* get first cluster */
        entry->first_cluster = FAT_READ_UINT16(&buff[ENTRY_FIRST_CLUSTER_OFFSET]);

        /* get file size */
        entry->file_size = FAT_READ_UINT32(&buff[ENTRY_FILE_SIZE_OFFSET]);

        fat_update_entry_list(entry);
    }

    return(retVal);
}

/**
 * @brief   Fuction update one entry to entry list (create if not available)
 *
 * @param   entry
 * @return  void
 */
static void fat_update_entry_list(fat_entry_struct_t *entry)
{
    fat_entry_struct_t *current_entry = sp_fat_entry_head;

    if(NULL == sp_fat_entry_head)
    {
        entry->index = 1;
        sp_fat_entry_head = entry;
        entry->next = NULL;
    }
    else
    {
        while(NULL != current_entry->next)
        {
            current_entry = current_entry->next;
        }
        entry->index = current_entry->index + 1;
        current_entry->next = entry;
        entry->next = NULL;
    }

    return;
}


/**
 * @brief   Function free current entry list
 *
 * @param   void
 * @return  void
 */
static void fat_free_entry_list(void)
{
    fat_entry_struct_t *current_entry = sp_fat_entry_head;
    fat_entry_struct_t *next_entry = NULL;

    while(NULL != current_entry)
    {
        next_entry = current_entry->next;
        free(current_entry);
        current_entry = next_entry;
    }
    sp_fat_entry_head = NULL;

    return;
}

/**
 * @brief   Function check cluster type (Table FAT entry value)
 *
 * @param   cluster index (referent to FAT table)
 * @return  type of cluster
 */
static fat_cluster_type_t fat_check_cluster_type(uint32_t cluster_index)
{
    fat_cluster_type_t retVal = reserved_cluster;

    if(0 == cluster_index)
    {
        retVal = free_cluster;
    }
    else if (1 == cluster_index)
    {
        retVal = internal_purpose_cluster;
    }
    else if (cluster_index >= s_fat_info.eoc_fat)
    {
        retVal = eoc_cluster;
    }
    else
    {
        switch(s_fat_info.eoc_fat)
        {
            case eoc_fat12:
            if(cluster_index >= 0x002 && cluster_index <= 0xFEF)
            {
                retVal = data_cluster;
            }
            else if (cluster_index >= 0xFF0 && cluster_index <= 0xFF5)
            {
                retVal = reserved_cluster;
            }
            else if(0xFF6 == cluster_index)
            {
                retVal = not_used_cluster;
            }
            else
            {
                retVal = bad_sector_cluster;
            }
            break;

            case eoc_fat16:
            if(cluster_index >= 0x0002 && cluster_index <= 0xFFEF)
            {
                retVal = data_cluster;
            }
            else if (cluster_index >= 0xFFF0 && cluster_index <= 0xFFF5)
            {
                retVal = reserved_cluster;
            }
            else if(0xFFF6 == cluster_index)
            {
                retVal = not_used_cluster;
            }
            else
            {
                retVal = bad_sector_cluster;
            }
            break;

            case eoc_fat32:
            if((cluster_index & 0x0FFFFFFF) >= 0x0000002 && (cluster_index & 0x0FFFFFFF) <= 0xFFFFFEF)
            {
                retVal = data_cluster;
            }
            else if ((cluster_index & 0x0FFFFFFF) >= 0xFFFFFF0 && (cluster_index & 0x0FFFFFFF) <= 0xFFFFFF5)
            {
                retVal = reserved_cluster;
            }
            else if(0xFFFFFF6 == (cluster_index & 0x0FFFFFFF))
            {
                retVal = not_used_cluster;
            }
            else
            {
                retVal = bad_sector_cluster;
            }
            break;
        }
    }

    return(retVal);
}

/**
 * @brief   Functon get next cluster
 *
 * @param   current cluster
 * @return  next cluster
 */
static uint32_t fat_get_next_cluster(uint32_t current_cluster)
{
    uint32_t retVal = 0;
    uint32_t index_sector_in_fat = 0; /* FAT */
    uint32_t index_byte_in_sector = 0;
    uint8_t sector_to_read = 1;
    uint8_t *buff = NULL;
    int32_t bytes_read = 0;

    switch(s_fat_info.eoc_fat)
    {
        case eoc_fat12:
        index_sector_in_fat = (3 * (current_cluster / 2)) / s_fat_info.bytes_per_sector;    /* sector offset */
        index_byte_in_sector = (3 * (current_cluster / 2)) % s_fat_info.bytes_per_sector;   /* byte offset*/
        /* if cluster addr lie in 2 consecutive sectors */
        if(((s_fat_info.bytes_per_sector - index_byte_in_sector) < 3) && ((s_fat_info.bytes_per_sector - index_byte_in_sector) > 0))
        {
            sector_to_read = 2;
        }
        buff = (uint8_t*)malloc(sector_to_read * s_fat_info.bytes_per_sector);
        bytes_read = kmc_read_multi_sector(s_fat_info.fat_offset + index_sector_in_fat, sector_to_read, buff);

        if(current_cluster % 2)
        {
            retVal = FAT_READ_FIELD_3BYTES(&buff[(sector_to_read - 1) * s_fat_info.bytes_per_sector + index_sector_in_fat]) >> 12;
        }
        else
        {
            retVal = FAT_READ_FIELD_3BYTES(&buff[(sector_to_read - 1) * s_fat_info.bytes_per_sector + index_sector_in_fat]) & 0x00000FFF;
        }
        free(buff);
        break;

        case eoc_fat16:
        index_sector_in_fat = (2 * current_cluster) / s_fat_info.bytes_per_sector;
        index_byte_in_sector = (2 * current_cluster) % s_fat_info.bytes_per_sector;
        buff = (uint8_t*)malloc(s_fat_info.bytes_per_sector);
        bytes_read = kmc_read_sector(s_fat_info.fat_offset + index_sector_in_fat, buff);

        retVal = FAT_READ_UINT16(&buff[index_byte_in_sector]);
        free(buff);
        break;

        case eoc_fat32:
        index_sector_in_fat = (4 * current_cluster) / s_fat_info.bytes_per_sector;
        index_byte_in_sector = (4 * current_cluster) % s_fat_info.bytes_per_sector;
        buff = (uint8_t*)malloc(sector_to_read * s_fat_info.bytes_per_sector);
        bytes_read = kmc_read_sector(s_fat_info.fat_offset + index_sector_in_fat, buff);

        retVal = FAT_READ_UINT16(&buff[index_byte_in_sector]);
        free(buff);
        break;
    }

    return(retVal);
}

/**
 * @brief   Functon with same memcpy() function
 *
 * @param   destination, sourse, number of element to copy
 * @return  void
 */
static void fat_myMemCpy(uint8_t *dest, uint8_t *src, int32_t n)
{
   int32_t i = 0;

   for(i = 0; i < n; i++)
   {
    dest[i] = src[i];
   }

   return;
}
