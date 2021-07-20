#include "main.h"

int main(void)
{
    char arr1[12] = "Ltsnnh";
    //char arr2[12] = "Ltsnnh1";
    char arr2[12] = {};
    scanf("%s%*c", arr2);
    // fgets(arr2, 12, stdin);  // fgets get enter

    if(strcmp(arr1,arr2)) // 0 -> Same | 1 -> Different
    {
        printf("Different string\n");
    }
    else
    {
        printf("Same string\n");
    }

    return 0;
}
