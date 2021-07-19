#include <stdio.h>
#include "common.h"

int main(void)
{
    int i = 0;
    char str[20];
    FILE *fp;

    fp = fopen("output.txt", "w");

    while(1)
    {
        i++;
        printf("Dong %d (Bam ENTER de exit): ", i);
        fgets(str, 20, stdin);
        if(str[0] == '\n')
            break;
        fputs(str, fp);
    }

    fclose(fp);

    return 0;
}
