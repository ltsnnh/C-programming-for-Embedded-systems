#include <stdio.h>
#include "common.h"

/* MODE BINARY */

/* COPY with fwrite & fread */

int main(void)
{
    int n;
    int arr[10] = {};
    FILE *f1, *f2;

    f1 = fopen("input.txt", "rb");
    f2 = fopen("output.txt", "wb");

    while((n = fread(arr, 4, 4, f1)) > 0)
    {
        fwrite(arr, 4, n, f2);
        fputc('\n', f2);
    }

    fclose(f1);
    fclose(f2);

    return 0;
}
