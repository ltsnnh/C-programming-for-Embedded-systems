#include "main.h"

int main(void)
{
    int a = 1, b = 2, c = 3, max;
    /* passing argument by value */
    max = passing_argument_by_value(a, b, c);
    printf("max passing argument by value = %d\n", max);
    max = 0;
    /* passing argument by reference */
    passing_argument_by_reference(&a, &b, &c, &max);
    printf("max passing argument by reference = %d\n", max);
    max = 0;
    /* pointer ---> function */
    max = max_abc(a, b, c, max_bc);
    printf("max writen by pointer -> function = %d\n", max);
    return 0;
}
