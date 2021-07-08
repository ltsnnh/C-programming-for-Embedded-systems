#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/********************************************************************
 * API
********************************************************************/
uint8_t func_import_array(int32_t *arr);
void func_remove_array(uint8_t num_element, int32_t *arr);
void func_print_array(uint8_t num_element, int32_t *arr);
void func_insert_element(uint8_t num_element, int32_t *arr);
uint8_t func_remove_element(uint8_t num_element, int32_t *arr);
void func_sort_increase_reduction(uint8_t num_element, int32_t *arr, bool stt);
void func_find_element(uint8_t num_element, int32_t *arr);
int32_t func_find_max_min(uint8_t num_element, int32_t *arr, bool stt);

#endif /* __MAIN_H__ */
