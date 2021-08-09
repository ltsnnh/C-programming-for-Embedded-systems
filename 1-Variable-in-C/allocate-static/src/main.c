#include "main.h"

static int a = 1; // global (.data)

int b = 2; // global (.data)

int main(void)
{
    int c = 4; // stack
    static int d = 3; // global (.data) (not stack)

    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n", &c);
    printf("%p\n", &d);
    return 0;
}
