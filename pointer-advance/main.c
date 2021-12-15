/*******************************************************************************
*                                Include
*******************************************************************************/
#include "pointer.h"

const arrsize = 10;

uint8_t main()
{
    uint8_t count = 0;
    uint8_t *ptr = NULL;
    
    /* Allocate for ptr */
    allocate10Bytes((uint8_t *)&ptr);
    
    /* Test ptr */
    CreatArr(ptr, arrsize);    
    printf("\n----------------\n");
    PrintArr(ptr, arrsize);
    
    free(ptr);
    return 0;
}

