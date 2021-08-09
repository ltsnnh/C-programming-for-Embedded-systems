#include <stdio.h>
#include "common.h"

#define max(A,B) (A)>(B)?(A):(B)

int main()
{
    int m = 5, n = 8;
    printf("%d\n", max(m,n));
    return 0;
}
