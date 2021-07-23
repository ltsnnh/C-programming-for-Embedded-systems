#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "srecord.h"

int main(void)
{
    FILE *fp = NULL;
    char file_name[20] = {}; /* File name should be less than 20 characters, subject to change */
    SRecord srec; /* Save current read line information */
    int status = SRECORD_OK; /* Return status of function srecord_parseSREC() */

    /* Enter file name */
    printf("FILE NAME: ");
    if (fgets(file_name, 20, stdin) == NULL) /* example: srec1.txt */
    {
        printf("Fail to read the input stream");
    }
    else
    {
        file_name[strcspn(file_name, "\n")] = '\0';   /* strcspn() returns the number of characters in string str1 which are not in the string str2. */
    }
    /* Open STREAM to FILE */
    fp = fopen(file_name, "r");
    if(fp == NULL)
    {
        printf("FILE %s does not exist.\n", file_name);
        printf("Press ENTER to exit");
        getchar();
        exit(1);
    }

    do
    {
        status = srecord_parseSREC(&srec, fp); /* function srecord_parseSREC() return only one error-code each a line (in order of priority check) */
        switch(status)
        {
            case SRECORD_ERROR_MISS_ASCII:
            printf("Line %u: ERROR MISS ASCII CHARACTER OR SREC TOO SHORT\n", srec.current_line);
            break;
            case SRECORD_ERROR_START:
            printf("Line %u: ERROR START IS NOT 'S'\n", srec.current_line);
            break;
            case SRECORD_ERROR_TYPE:
            printf("Line %u: ERROR TYPE UNKNOWN\n", srec.current_line);
            break;
            case SRECORD_ERROR_SYNTAX:
            printf("Line %u: ERROR SYNTAX: NON-HEX CHARACTER EXIST\n", srec.current_line);
            break;
            case SRECORD_ERROR_BYTE_COUNT:
            printf("Line %u: ERROR BYTE COUNT\n", srec.current_line);
            break;
            case SRECORD_ERROR_CHECK_SUM:
            printf("Line %u: ERROR CHECK SUM\n", srec.current_line);
            break;
            case SRECORD_ERROR_S5_S6:
            printf("Line %u: ERROR WRONG FORMAT S5 S6\n", srec.current_line);
            break;
            case SRECORD_ERROR_LINE_COUNT:
            printf("Line %u: ERROR LINE COUNT\n", srec.current_line);
            break;
            default:
            srecord_printSREC(&srec); /* if not error, print infomation S1/S2/S3 */
            break;
        }
    }
    while(status != SRECORD_EOF);

    printf("FILE is closing...\n");

    fclose(fp);

    return 0;
}
