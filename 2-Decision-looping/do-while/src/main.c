#include <stdio.h>
#include "common.h"

int a[] = {9, 4, 7, -3, 14};
int n = sizeof(a) / sizeof(int);

int main()
{
    int i = -1;
    do
        ++i;
    while(a[i] >= 0 && i < n);
    if(i < n)
        printf("Phan tu am dau tien = a[%d] = %d\n", i, a[i]);
    else
        printf("Day ko co phan tu am\n");

    return 0;
}
