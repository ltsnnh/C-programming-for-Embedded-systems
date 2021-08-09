#include <stdio.h>
#include <stdint.h>
#include "common.h"

int main(void)
{
    uint16_t a = 0xA1B6;
    int f[6];
    f[0] = a & 0xFF;
    f[1] = a | 0xFF;
    f[2] = a ^ 0xFFFF;
    f[3] = a << 8;
    f[4] = a >> 8;
    f[5] = ~a;

    for(int i = 0; i < 6; i++)
    {
        printf("f[%d] = %04x\n", i, f[i]);    //%x de in ra so nguyen dang co so 16
    }

    return 0;
}