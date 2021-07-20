#include "libincl.h"

uint8_t func_import_array(int32_t *arr)
{
    uint8_t num_element = 0;    /* NULL */
    uint8_t i = 0;

    printf("Nhap so phan tu cua mang (<=128): ");
    scanf("%hhu", &num_element);
    printf("Nhap %hhu phan tu cua mang\n", num_element);
    for( ; i < num_element; i++)
    {
        printf("Nhap phan tu thu %hhu cua mang: ", i + 1);
        scanf("%d%*c", &arr[i]);    /* fw = %*.c exit \n */
    }
    
    return(num_element);
}
