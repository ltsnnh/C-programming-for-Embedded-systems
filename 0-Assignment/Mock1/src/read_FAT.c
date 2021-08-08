#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "FAT.h"
#include "read_FAT.h"

/********************************************************************
 * Prototypes
********************************************************************/
static void readfat_print_directory(fat_entry_struct_t *entry_head);
static void readfat_print_error(fat_error_code_t error_code);
static void readfat_printf_file(uint8_t *buff, uint32_t size);

/********************************************************************
 * Code
********************************************************************/
/**
 * @brief   Read FAT file system
 *
 * @param   void
 * @return  void
 */
 void read_FAT(void)
 {
    fat_error_code_t error_code = error_code_success;
    int8_t file_name[256] = {};
    fat_entry_struct_t *entry_head = NULL;
    fat_entry_struct_t *entry = NULL;
    int32_t commit = 0;
    uint8_t *file_buffer = NULL;
    uint32_t file_size = 0;
    bool status = false;

    printf("FILE NAME: ");
    if(fgets(file_name, 256, stdin) == NULL) /* example: floppy.img */
    {
        printf("Fail to read the input stream");
    }
    else
    {
        file_name[strcspn(file_name, "\n")] = '\0';   /* strcspn() returns the number of characters in string str1 which are not in the string str2. */
    }
    error_code = fat_init((int8_t*)file_name, &entry_head);
    if(error_code_success == error_code)
    {
        do
        {
            status = false;
            readfat_print_directory(entry_head);
            printf("Enter option (0 to exit): ");
            scanf("%d%*c", &commit);
            entry = entry_head;
            while(NULL != entry)
            {
                if(commit == entry->index)
                {
                    status = true;
                    break;
                }
                else
                {
                    entry = entry->next;
                }
            }
            if(true == status)
            {
                if(entry->subdir)
                {
                    error_code = fat_read_directory(entry->first_cluster, &entry_head);
                    if(error_code_success != error_code)
                    {
                        readfat_print_error(error_code);
                    }
                }
                else
                {
                    file_size = entry->file_size;
                    file_buffer = (uint8_t*)malloc(file_size);
                    error_code = fat_read_file(entry->first_cluster, file_buffer, file_size);
                    if(error_code_success == error_code)
                    {
                        readfat_printf_file(file_buffer, file_size);
                    }
                    else
                    {
                        readfat_print_error(error_code);
                    }
                    free(file_buffer);
                }
            }
        }while(commit > 0);
    }
    error_code = fat_deinit();
    if(error_code_success != error_code)
    {
        readfat_print_error(error_code);
    }
    printf("Exiting...!\n");

    return;
 }

/**
 * @brief   Function printf directory
 *
 * @param   head of entry list
 * @return  void
 */
 static void readfat_print_directory(fat_entry_struct_t *entry)
 {
    printf("%-8s%-24s%-16s%-16s%-16s\n","Index", "Name", "Type", "Size", "Date modified");
    while(NULL != entry)
    {
        printf("%-8hu%-24s",entry->index, entry->name);
        if(entry->subdir)
        {
            printf("%-16s", "Folder");
        }
        else
        {
            printf("%-16s", "File");
        }
        printf("%-16u", entry->file_size);
        printf("%hhu/%hhu/%hu\n", entry->modified_time.day, entry->modified_time.month, entry->modified_time.year);
        entry = entry->next;
    }

    return;
}

/**
 * @brief   Function print file
 *
 * @param   buffer include data file, size of file
 * @return  void
 */
static void readfat_printf_file(uint8_t *buff, uint32_t size)
{
    uint32_t i = 0;

    for(i = 0; i < size; i++)
    {
        printf("%hhx", buff[i]);
    }
    printf("\n");

    return;
}

/**
 * @brief   Print error code
 *
 * @param   error code
 * @return  void
 */
static void readfat_print_error(fat_error_code_t error_code)
{
    switch(error_code)
    {
        case error_code_init_failed:
        printf("Error init failed\n");
        break;
        case error_code_read_file_failed:
        printf("Error read file failed\n");
        break;
        case error_code_read_directory_failed:
        printf("Error read directory failed\n");
        break;
        case error_code_deinit_failed:
        printf("Error deinit failed\n");
        break;
        default:
        printf("Success!\n");
    }

    return;
}
