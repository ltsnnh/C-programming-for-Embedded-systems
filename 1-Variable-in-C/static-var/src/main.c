#include <stdio.h>
#include "update.h"

static int a = 10;

int main(void)
{
    printf("%d\n", a);
    update(&a);
    printf("%d\n", a);

    return 0;
}
