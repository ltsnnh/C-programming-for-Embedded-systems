#include "sysincl.h"

void task_1(int *p)
{
    scanf("%d", p);
    while(*p <= 0)
    {
        printf("nhap sai. nhap lai! = ");
        scanf("%d", p);
    }

    return;
}