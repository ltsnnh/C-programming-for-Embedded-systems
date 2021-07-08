#include "libincl.h"

/********************************************************************
 * Definitions
********************************************************************/
#define MAX(A, B)   (((A)>(B))?(A):(B))
#define MIN(A, B)   (((A)<(B))?(A):(B))

/********************************************************************
 * Code
********************************************************************/
int32_t func_find_max_min(uint8_t num_element, int32_t *arr, bool stt)
{
    int32_t m = arr[0];
    uint8_t i = 1;

    if(stt == true)
    {
        for( ; i < num_element; i++)
        {
            m = MIN(m, arr[i]);
        }
    }
    else
    {
        for( ; i < num_element; i++)
        {
            m = MAX(m, arr[i]);
        }
    }
    
    return(m);
}
