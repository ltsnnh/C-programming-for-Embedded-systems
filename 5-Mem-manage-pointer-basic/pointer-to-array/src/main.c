#include "main.h"

int main(void)
{
    int array[5];
    import(array);
    print(array);
    return 0;
}

void import(int *arr)
{
    char i = 0;
    for ( ; i < 5; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d%*c", arr + i);
    }
    return;
}

void print(int *arr)
{
    char i = 0;
    printf("[");
    for( ; i < 4; i++)
    {
        printf("%d\t", *(arr + i));
    }
    printf("%d]\n", *(arr + i));
    return;
}
