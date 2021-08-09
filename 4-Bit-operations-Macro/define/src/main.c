#include <stdio.h>
#include "common.h"

#define in printf
#define N 100

int main()
{
    int M = 200;
    in("M = %d, N = %d\n", M, N);
    #define M 300
    in("M = %d, N = %d\n", M, N);
    #undef M
    #define M (N + 400)
    in("M = %d, N = %d\n", M, N);
    return 0;
}
