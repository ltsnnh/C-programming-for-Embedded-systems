#include "allocate.h"

bool allocate10Bytes(uint8_t *outPtr)
{
    bool stt = true;
    uint8_t **PtrtoPtr = (uint8_t**)outPtr; /* (outPtr -> Ptr) => (PtrtoPtr -> Ptr) */
    
    *PtrtoPtr = (uint8_t*) malloc(10 * sizeof(uint8_t));    /* Ptr = pointer */
    if(*PtrtoPtr == NULL)
    {
        stt = false;
    }

    return stt;
}
