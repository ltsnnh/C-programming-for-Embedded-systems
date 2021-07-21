#include <stdio.h>
#include "common.h"

/* MODE TEXT */

int main(void)
{
    int i = 0;
    char str[10];
    FILE *fp;

    fp = fopen("input.txt", "r");

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
        i++;
        fgets(str, 8, fp);
        if(feof(fp))
            break;
        printf("Dong %d: %s", i, str);
    }

    fclose(fp);

    return 0;
}
