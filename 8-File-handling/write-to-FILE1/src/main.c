#include <stdio.h>
#include "common.h"

int main(void)
{
    FILE *f;    /* Bien con tro tep */

    f = fopen("file.txt", "wt");    /* Mo tep file.txt ghi theo KIEU VAN BAN */
    fprintf(f, "%2d\n%2d\n%2d", 56, 7, 8);  /* Ghi 3 dong len tep f */
    fclose(f);  /* Dong tep */

    return 0;
}
