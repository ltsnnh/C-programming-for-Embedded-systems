#include "sysincl.h"

void task_2(int m, int n, int **a)
{
    int i, j;
    int buf;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &buf);
            *(*(a + i) + j) = buf;
        }

    /* in mang nguyen a 2 chieu kich thuoc m x n */
    printf("mang 2D %dx%d:\n", m, n);
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("\t%d", a[i][j]);
        }
        printf("\n");
    }

    return;
}