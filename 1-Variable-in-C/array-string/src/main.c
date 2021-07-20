#include "main.h"

int main(void)
{
    char *c, arr[10];
    c = "Ltsnnh";   /* arr = "Ltsnnh";  error: assignment to expression with array type */
    puts(c);
    fgets(arr, 10, stdin);  // instead: gets() since C11
    puts(arr);
    return 0;
}
