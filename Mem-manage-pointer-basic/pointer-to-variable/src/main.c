#include "main.h"

int main(void)
{
    int a, *ptr;
    ptr = &a;
    printf("*ptr = ");
    scanf("%d", ptr);
    printf("a = %d\n", a);
    return 0;
}
