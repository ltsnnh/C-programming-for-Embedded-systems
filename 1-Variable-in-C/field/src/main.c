#include "main.h"

union
{
    struct
    {
        uint32_t a1;
        uint32_t a2;
    } s;

    struct
    {
        uint32_t n1:16;
        uint32_t:16;
        uint32_t n2:8;
        uint32_t n3:8;
        uint32_t n4:16;
    } f;
} u;

int main(void)
{
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t d;
    u.s.a1 = 0x0000f0f0;    // 61680
    u.s.a2 = 0x0000f00f;
    a = u.f.n1; // 0xf0f0 = 61680
    b = u.f.n2; // 0x0f = 15
    c = u.f.n3; // 0xf0 = 240
    d = u.f.n4; // 0x0000 = 0
    printf("%d\t%d\t%d\t%d\n", a, b, c, d);
    
    return 0;
}
