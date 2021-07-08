#include "main.h"

int main(void)
{
    uint8_t *Ptr = NULL;
    bool stt = allocate10Bytes((uint8_t*)&Ptr); /* outPtr -> Ptr */

    if(stt == true)
    {
        printf("successful allocation\n");
    }
    else
    {
        printf("allocation failed\n");
    }

    return 0;
}
