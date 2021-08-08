#ifndef __FAT_H__
#define __FAT_H__

/********************************************************************
 * Definitions
********************************************************************/
typedef enum
{
    error_code_success = 0,
    error_code_init_failed = -1,
    error_code_read_file_failed = -2,
    error_code_read_directory_failed = -3,
    error_code_deinit_failed = -4
}fat_error_code_t;

typedef struct
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
}fat_time_struct_t;

typedef struct entry
{
    char name[255];                     /* SFN length = 8, LFN supports a maximum length of 255 */
    char extension[4];                  /* SFN extension length = 3 */
    bool subdir;                        /* true = folder / false = file */
    fat_time_struct_t create_time;      /* Create time */
    fat_time_struct_t modified_time;    /* Last modified time */
    uint32_t first_cluster;             /* Start of file in clusters in FAT12, FAT16 and FAT32 */
    uint32_t file_size;                 /* File size in bytes */
    /* manage purpose */
    uint16_t index;                     /* For purpose display and get commit deputation */
    struct entry *next;                 /* Self-pointing structure */
}fat_entry_struct_t;

/********************************************************************
 * API
********************************************************************/
fat_error_code_t fat_init(int8_t *file_name, fat_entry_struct_t **entry_head);
fat_error_code_t fat_read_directory(uint32_t first_cluster, fat_entry_struct_t **entry_head);
fat_error_code_t fat_read_file(uint32_t first_cluster, uint8_t *p_buff, uint32_t file_size);
fat_error_code_t fat_deinit(void);

#endif  /* __FAT_H__ */
