#include "sysincl.h"

int main(void)
{
	int m, n, k;
    int **a = NULL, ***b = NULL;
    int i, j;

    /* nhap 3 so nguyen duong m, n, k */
    printf("nhap gia tri m = ");
    task_1(&m);
    printf("nhap gia tri n = ");
    task_1(&n);
    printf("nhap gia tri k = ");
    task_1(&k);

    /* cap phat mang nguyen a 2 chieu kich thuoc m x n */
    a = (int**)malloc(m * sizeof(int *));       // cap phat dong mang cac con tro cap 1
        for (i = 0; i < m; i++)
        {
            a[i] = (int*)malloc(n * sizeof(int));   // cap phat dong tung con tro cap 1 trong tung mang
        }
    /* nhap mang nguyen a 2 chieu kich thuoc m x n */
    task_2(m, n, a);

    /* cap phat mang nguyen b 3 chieu kich thuoc m x n x k */
    b = (int***)malloc(m * sizeof(int **));       // cap phat dong mang 2-D cac con tro cap 2
        for (i = 0; i < m; i++)
        {
            b[i] = (int**)malloc(n * sizeof(int *));   // cap phat dong mang cac con tro cap 1
            for(j = 0; j < n; j++)
            {
                b[i][j] = (int*)malloc(k * sizeof(int));   // cap phat dong tung con tro cap 1 trong tung mang
            }
        }
    /* nhap mang nguyen b 3 chieu kich thuoc m x n x k */
    task_3(m, n, k, b);

	return 0;
}