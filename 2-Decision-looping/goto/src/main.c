#include <stdio.h>
#include "common.h"

int main(void)
{
    int a, b;
    tt:
    printf("Nhap 2 so a, b sao cho a > b\na = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    if(a > b)
        ;
    else
        goto tt;

    return 0;
}
