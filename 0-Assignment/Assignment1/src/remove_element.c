#include "libincl.h"

uint8_t func_remove_element(uint8_t num_element, int32_t *arr)
{
    uint8_t i = 0;  /* NULL */
    uint8_t k = 0;  /* NULL */
    uint8_t remove_stt = 0;

    printf("Nhap vi tri muon xoa phan tu (<= %hhu): ", num_element);
    scanf("%hhu%*c", &k);   /* fw = %*.c exit \n */
    if(k <= num_element)
    {
        for(i = k; i < num_element; i++)
        {
            arr[i - 1] = arr[i];
        }
        arr[i] = 0;
        remove_stt = 1;
    }
    else
    {
        printf("Khong co phan tu o vi tri %hhu\n", k);
    }

    return(remove_stt);
}
