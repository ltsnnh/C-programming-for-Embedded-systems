#include <stdio.h>
#include "main.h"

static inline int sum(int m, int n)
{
    return(m+n);
}

int main(void)
{
    int a = 1, b = 2;
    printf("sum = %d\n", sum(a, b));
    return 0;
}
