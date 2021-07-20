#include "main.h"

const int a = 1; // code & const

int b = 2; // global (.data)

int main(void)
{
    int c = 4; // stack
    const int d = 3; // stack (not code & const)

    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n", &c);
    printf("%p\n", &d);
    return 0;
}
