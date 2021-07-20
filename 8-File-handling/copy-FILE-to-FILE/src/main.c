#include <stdio.h>
#include <stdlib.h> /* exit() */
/* #include <conio.h>   header of MS-DOS not variable on LINUX */
#include <string.h> /* strcspn() */
#include "common.h"

/* MODE NHI PHAN */

int main(void)
{
    int c = 0;
    char t1[14] = {}, t2[14] = {};
    FILE *f1, *f2;

    printf("TEP NGUON: ");
    if (fgets(t1, 14, stdin) == NULL)  /* input.txt */
    {
        printf("Fail to read the input stream");
    }
    else
    {
        t1[strcspn(t1, "\n")] = '\0';
    }

    printf("TEP DICH: ");
    if (fgets(t2, 14, stdin) == NULL)  /* output.txt */
    {
        printf("Fail to read the input stream");
    }
    else
    {
        t2[strcspn(t2, "\n")] = '\0';
    }

    f1 = fopen(t1, "rb");
    if(f1 == NULL)
    {
        printf("TEP %s khong ton tai.\n", t1);
        printf("Press ENTER to exit");
        getchar();
        exit(1);
    }

    f2 = fopen(t2, "wb");

    /* COPY */
    while((c = fgetc(f1)) != EOF)
    {
        fputc(c, f2);
    }

    /* if use feof() functon */
    /* khong thuc su chinh xac, f2 se dai hon f1 1 ky tu ma 255 */
    /* do ham feof() chi dc cap nhat gia tri sau 1 cau lenh doc */
    /*
    while(!feof(fi))
    {
        fputc(fgetc(f1), f2);
    }
    */

    fclose(f1);
    fclose(f2);

    return 0;
}
