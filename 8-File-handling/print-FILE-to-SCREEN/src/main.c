#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

/* MODE BINARY */

int main(void)
{
    int c, i;
    char t1[14] = {};
    FILE *fp;

    printf("TEP NGUON: ");
    if (fgets(t1, 14, stdin) == NULL)  /* input.txt */
    {
        printf("Fail to read the input stream");
    }
    else
    {
        t1[strcspn(t1, "\n")] = '\0';
    }

    fp = fopen(t1, "rb");
    if(fp == NULL)
    {
        printf("TEP %s khong ton tai.\n", t1);
        printf("Press ENTER to exit");
        getchar();
        exit(1);
    }

    /* IN MA */
    i = 0;
    while((c = fgetc(fp)) != EOF)
    {
        printf("%-4d", c);
        if(c < 32)
        {
            c = 46;
        }
        printf("%-4c", c);
        i++;
        if(i == 4)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n");

    fclose(fp);

    return 0;
}
