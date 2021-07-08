#include "libincl.h"

void func_sort_increase_reduction(uint8_t num_element, int32_t *arr, bool stt)
{
    uint8_t i = 0;
    uint8_t j = 0;  /* NULL */

    /* BubbleSort */
    if(stt == true)
    {
        for( ; i < num_element - 1; i++)
        {
            for(j = i + 1; j < num_element; j++)
            {
                if(arr[i] < arr[j])
                {
                    arr[i] += arr[j];
                    arr[j] = arr[i] - arr[j];
                    arr[i] -= arr[j];
                }
            }       
        }
    }
    else
    {
        for( ; i < num_element - 1; i++)
        {
            for(j = i + 1; j < num_element; j++)
            {
                if(arr[i] > arr[j])
                {
                    arr[i] += arr[j];
                    arr[j] = arr[i] - arr[j];
                    arr[i] -= arr[j];
                }
            }   
        }
    }
    
    return;
}
