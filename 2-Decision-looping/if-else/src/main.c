#include <stdio.h>
#include "common.h"

int main(void)
{
    int c, d, max, min;
    printf("Nhap vao 2 so nguyen c, d: ");
    scanf("%d%d", &c, &d);

    if(c > d)
    {
        max = c;
        min = d;
        printf("max = %d\nmin = %d\n", max, min);
    }
    else if(c < d)
    {
        max = d;
        min = c;
        printf("max = %d\nmin = %d\n", max, min);
    }
    else
    {
        max = min = c = d;
        printf("max = min = c = d = %d\n", c);
    }

    return 0;
}