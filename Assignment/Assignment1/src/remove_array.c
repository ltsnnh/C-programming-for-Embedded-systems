#include "libincl.h"

void func_remove_array(uint8_t num_element, int32_t *arr)
{
    uint8_t i = 0;

    for( ; i < num_element; i++)
    {
        arr[i] = 0;
    }
    
    return;
}
