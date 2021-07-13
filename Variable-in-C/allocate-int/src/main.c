#include "main.h"

int main(void)
{
    uint32_t a = 0x0A0B0C0Du;
    uint8_t *c = (uint8_t*)&a;
    printf("%p = %hhd\n", c, *c);
    printf("%p = %hhd\n", c + 1, *(c + 1));
    printf("%p = %hhd\n", c + 2, *(c + 2));
    printf("%p = %hhd\n", c + 3, *(c + 3));
    return 0;
}
