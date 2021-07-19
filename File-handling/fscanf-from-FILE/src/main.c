#include <stdio.h>
#include "common.h"

int main(void)
{
    FILE *fp;
    int i = 0, n = 0;
    float x[10] = {}, y[10] = {};

    fp = fopen("input.txt", "rt");

    fscanf(fp, "%d", &n);

    for( ; i < n; i++)
    {
        fscanf(fp, "%f%f", &x[i], &y[i]);
    }

    fclose(fp);

    for(i = 0; i < n; i++)
    {
        printf("%.1f\t%.1f\n", x[i], y[i]);
    }

    return 0;
}
