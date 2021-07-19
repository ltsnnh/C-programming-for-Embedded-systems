#include <stdio.h>
#include "common.h"

/* MODE BINARY */

/* putw & getw : convert to short int */

int main(void)
{
    FILE *fp;
    int i = 0;

    fp = fopen("medium.txt", "wb");
    for(i = 0; i < 10; i++)
        putw(i, fp);
    fclose(fp);
    fp = fopen("medium.txt", "rb");
    while((i = getw(fp)) != EOF)
        printf("%d\n", i);
    fclose(fp);

    return 0;
}
