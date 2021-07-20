#include <stdio.h>
#include "common.h"

enum {a, b, c, d, e, f};

int main(void)
{
    switch(2)
    {
        case a:
        printf("%d\n", 0);
        break;
        case b:
        printf("%d\n", 1);
        break;
        case c: /* case without break(); */
        printf("%d\n", 2);
        case d:
        printf("%d\n", 3);
        break;
        case e:
        printf("%d\n", 4);
        break;
        case f:
        printf("%d\n", 5);
        break;
        default:
        break;
    }


    return 0;
}
