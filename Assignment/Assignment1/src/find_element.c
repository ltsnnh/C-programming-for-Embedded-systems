#include "libincl.h"

void func_find_element(uint8_t num_element, int32_t *arr)
{
    int32_t x = 0;  /* NULL */
    uint8_t i = 0;
    bool stt = true;

    printf("Nhap phan tu can tim: ");
    scanf("%d%*c", &x); /* fw = %*.c exit \n */
    for( ; (i < num_element) && (stt == true); i++)
    {
        if(x == arr[i])
        {
            printf("Co phan tu = %d trong mang\n", x);
            stt = false;
        }
    }
    if(stt == true)
    {
        printf("Khong co phan tu = %d trong mang\n", x);
    }
    
    return;
}
