#include <stdio.h>
#include <string.h>
#include "common.h"

/* MODE TEXT */

int main(void)
{
    char str[50];
    FILE *fp1;
    FILE *fp2;

    fp1 = fopen("srec1.srec", "r");

    fp2 = fopen("output.txt", "w");

    /* TH: <last_word><EOF> */
    /*do
    {
        i++;
        fgets(str, 50, fp);
        printf("Dong %d: %s", i, str);
    }
    while(!feof(fp));
    printf("\n");*/

    /* TH: <last_word><space><EOF> */
    while(1)
    {
        fgets(str, 50, fp1);    /* also get <CR> <LF> */
        if(feof(fp1))
            break;
        fputs(str, fp2);        /* also put <CR> <LF> */
        fprintf(fp2, "%lu\n", strcspn(str, "\0"));      /* contain <CR> <LF> */
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
