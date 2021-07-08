#include "libincl.h"

void func_print_array(uint8_t num_element, int32_t *arr)
{
    uint8_t i = 0;

    printf("In mang: [");
    for( ; i < (num_element - 1); i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("%d]\n", arr[i]);
    
    return;
}
