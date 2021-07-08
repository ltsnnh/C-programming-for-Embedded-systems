#include "main.h"

int main(void)
{
    uint8_t array[3];       /* array[0], array[1] contain input numbers, array[2] contains result */
    uint8_t commit = 'y';
    int8_t clear_stdin = 0; /* NULL */

    while(commit == 'y')
    {
        printf("Nhap 2 so duong (0 <= x <= 255)\n");
        printf("a = ");
        scanf("%hhu%*c", &array[0]);    /* fw = %*.c exit \n */
        printf("b = ");
        scanf("%hhu%*c", &array[1]);    /* fw = %*.c exit \n */
        absoluteValue(array);
        printf("a = %hhu\t\
            b = %hhu\t\
            |a - b| = %hhu\n", array[0], array[1], array[2]);
        printf("Ban co muon nhap nua khong?\n\
            y = yes\t\
            n = no\n");
        commit = getchar();
        if(commit != '\n')  /* fflush(stdin); */
        {
            do
            {
                clear_stdin = getchar();
            }while(clear_stdin != '\n');
        }
    }

    return 0;
}
