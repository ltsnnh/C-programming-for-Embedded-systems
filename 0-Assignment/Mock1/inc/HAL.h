#ifndef __HAL_H__
#define __HAL_H__

/********************************************************************
 * API
********************************************************************/
/**
 * @brief   Open FILE.
 *
 * @param   file name.
 * @return  true if success | false if error.
 */
bool kmc_open_file(int8_t *file_name);

/**
 * @brief   Read sector position index, save into array which is pointed by buff.
 *
 * @param   index, *buff.
 * @return  number of bytes is read.
 */
int32_t kmc_read_sector(uint32_t index, uint8_t *buff);

/**
 * @brief   Update default sector size.
 *
 * @param   sector size.
 * @return  void.
 */
void kmc_update_sector_size(uint16_t sector_size);

/**
 * @brief   Read number of contiguously sectors started at position index, save into array which is pointed by buff.
 *
 * @param   index, num, *buff.
 * @return  number of bytes is read.
 */
int32_t kmc_read_multi_sector(uint32_t index, uint32_t num, uint8_t *buff);

/**
 * @brief   Close FILE.
 *
 * @param   void.
 * @return  true if success | false if error.
 */
bool kmc_close_file(void);

#endif  /* __HAL_H__ */
