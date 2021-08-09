#include <stdio.h>
#include "common.h"

#define MAX 100

int main()
{
    #if MAX > 200
    printf("Bien dich voi MAX > 200\n");
    #else
    printf("Bien dich voi MAX <= 200\n");
    #endif // MAX
    return 0;
}
