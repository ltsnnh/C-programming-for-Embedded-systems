#include "libincl.h"

void func_insert_element(uint8_t num_element, int32_t *arr)
{
    uint8_t i = 0;  /* NULL */
    uint8_t m = 0;  /* NULL */

    printf("Nhap vi tri muon them phan tu (<= %hhu): ", num_element);
    scanf("%hhu", &m);
    for(i = num_element; i >= m; i--)
    {
        arr[i] = arr[i - 1];
    }
    printf("Nhap phan tu: ");
    scanf("%d%*c", &arr[m - 1]);    /* fw = %*.c exit \n */
    
    return;
}
