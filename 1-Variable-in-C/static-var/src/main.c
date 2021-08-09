#include <stdio.h>
#include "update.h"

int update(int m);

static int a = 10;                      /* a global */

int main(void)
{
    printf("%d\n", a);          // 10   /* a global */
    printf("%d\n", update(a));  // 10
    printf("%d\n", update(a));  // 20
    printf("%d\n", update(a));  // 0
    printf("%d\n", a);          // 10   /* a global */

    return 0;
}

int update(int m)
{
    static int a = 0;                   /* a local */
    a = a + m;                          /* a local */
    if(a == 30)
        a = 0;

    return(a);                          /* a local */
}
