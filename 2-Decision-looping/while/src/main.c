#include <stdio.h>
#include "common.h"

float x[] = {4, 6, 8, 3.5}, \
  y[] = {2.6, 3.2, 4, 7};


int main()
{
    float s = 0.0;
    int i = -1;
    while (++i < 4)
    s += x[i] * y[i];
    printf("Tich vo huong = %0.2f\n", s);

    return 0;
}