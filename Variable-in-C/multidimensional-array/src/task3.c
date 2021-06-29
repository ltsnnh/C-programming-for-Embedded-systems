#include "sysincl.h"

void task_3(int m, int n, int k, int ***b)
{
    int i, j, o;
    int buf;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            for(o = 0; o < k; o++)
            {
                printf("b[%d][%d][%d] = ", i, j, o);
                scanf("%d", &buf);
                *(*(*(b + i) + j) + o) = buf;
            }
        }
    }

    /* in mang nguyen b 3 chieu kich thuoc m x n x k */
    for(i = 0; i < m; i++)
    {
        printf("m = %d\n", i);
        for(j = 0; j < n; j++)
        {
            for(o = 0; o < k; o++)
            {
                printf("\t%d", b[i][j][o]);
            }
            printf("\n");
        }
    }

    return;
}