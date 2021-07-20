#include "main.h"

int main(void)
{
    uint32_t a = 0x0A0B0C0Du;
    uint8_t *c = (uint8_t*)&a;
    printf("%p = %hhd\n", c, *c);           // 0x0D
    printf("%p = %hhd\n", c + 1, *(c + 1)); // 0x0C
    printf("%p = %hhd\n", c + 2, *(c + 2)); // 0x0B
    printf("%p = %hhd\n", c + 3, *(c + 3)); // 0x0A
    return 0;
}
