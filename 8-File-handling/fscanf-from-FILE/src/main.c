#include <stdio.h>
#include "common.h"

int main(void)
{
    FILE *fp;
    int i = 0, n = 0;
    unsigned char x[10] = {}, y[10] = {};

    fp = fopen("input.txt", "rt");

    fscanf(fp, "%d", &n);

    for(i = 0 ; i < n; i++)
    {
        fscanf(fp, "%2hhx%2hhx", &x[i], &y[i]);
    }

    fclose(fp);

    for(i = 0; i < n; i++)
    {
        printf("%hhu\t%hhu\n", x[i], y[i]);
    }

    return 0;
}
