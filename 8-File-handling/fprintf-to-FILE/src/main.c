#include <stdio.h>
#include "common.h"

int main(void)
{
    FILE *fp;
    int i = 0;

    fp = fopen("output.txt", "wt");

    for( ; i < 10; i++)
    {
        fprintf(fp, "Column %2d\n", i);
    }

    fclose(fp);

    return 0;
}
