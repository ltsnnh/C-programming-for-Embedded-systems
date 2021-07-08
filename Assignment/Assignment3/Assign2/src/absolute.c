#include "absolute.h"

void absoluteValue(uint8_t *data)
{
    int16_t result = data[0] - data[1];     /* 255 >= (uint8_t - uint8_t) >= -255: overflow type uint8_t */
    data[2] = (uint8_t)ABSOLUTE(result);    /* |uint8_t - uint8_t| inside type uint8_t */
    return;
}
