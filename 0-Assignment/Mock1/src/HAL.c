#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "HAL.h"

/********************************************************************
 * Definitions
********************************************************************/
#define KMC_DEFAULT_SECTOR_SIZE     512

/********************************************************************
 * Variables
********************************************************************/
static FILE *fp = NULL;
static uint16_t s_kmc_sector_size = KMC_DEFAULT_SECTOR_SIZE;
static int32_t s_kmc_size_of_uint8t = sizeof(uint8_t);

/********************************************************************
 * Code
********************************************************************/
/**
 * @brief   Open FILE.
 *
 * @param   file name.
 * @return  true if success | false if error.
 */
bool kmc_open_file(int8_t *file_name)
{
    bool status = true;

    fp = fopen(file_name, "rb");
    if(fp == NULL)
    {
        status = false;
    }
    s_kmc_sector_size = KMC_DEFAULT_SECTOR_SIZE;

    return(status);
}

/**
 * @brief   Read sector position index, save into array which is pointed by buff.
 *
 * @param   index, *buff.
 * @return  number of bytes is read.
 */
int32_t kmc_read_sector(uint32_t index, uint8_t *buff)
{
    int32_t retVal = 0;

    if(0 == fseek(fp, index * s_kmc_sector_size, SEEK_SET))
    {
        retVal = fread(buff, s_kmc_size_of_uint8t, s_kmc_sector_size, fp);
    }

    return(retVal);
}

/**
 * @brief   Update default sector size.
 *
 * @param   sector size.
 * @return  void.
 */
void kmc_update_sector_size(uint16_t sector_size)
{
    s_kmc_sector_size = sector_size;

    return;
}

/**
 * @brief   Read number of contiguously sectors started at position index, save into array which is pointed by buff.
 *
 * @param   index, num, *buff.
 * @return  number of bytes is read.
 */
int32_t kmc_read_multi_sector(uint32_t index, uint32_t num, uint8_t *buff)
{
    int32_t retVal = 0;

    if(0 == fseek(fp, index * s_kmc_sector_size, SEEK_SET))
    {
        retVal = fread(buff, s_kmc_size_of_uint8t, num * s_kmc_sector_size, fp);
    }

    return(retVal);
}

/**
 * @brief   Close FILE.
 *
 * @param   void.
 * @return  true if success | false if error.
 */
bool kmc_close_file(void)
{
    bool status = true;

    if(fclose(fp) == EOF)
    {
        status = false;
    }

    return(status);
}
