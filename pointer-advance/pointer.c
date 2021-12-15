/*!*****************************************************************************
* @file            pointer.c
* @brief           Define functions of pointer.h
* @author          ThangNC23
* @deadline        24/08/21
*******************************************************************************/

/*******************************************************************************
*                                Include
*******************************************************************************/
#include "pointer.h"


/*******************************************************************************
*                               Prototype
*******************************************************************************/

/*!*****************************************************************************
* @function        clean_stdin
* @brief           check '\n' for scanf
* @return          1
* @description     this function used for function t_uscanf
*******************************************************************************/
static uint8_t clean_stdin();

/*******************************************************************************
*                                 Code
*******************************************************************************/
bool allocate10Bytes(uint8_t *outPtr)
{
    bool checkOK = false;
    
    uint8_t **ppoutPtr = (uint8_t **)outPtr;
    *ppoutPtr = (uint8_t *) malloc(10 * sizeof(uint8_t));
    if(*ppoutPtr == NULL)
    {
        checkOK = false;
    }
    else
    {
        checkOK = true;
    }
    return checkOK;
}

uint8_t clean_stdin(void)
{
    while (getchar() != '\n')
    {
        /* do not nothing */
    }
    return 1;
}

void t_uscanf(uint8_t *pintenger)
{
    uint8_t cvar;
    
    do
    {
        /* do not nothing */
    }while (((scanf("%hhu%c", pintenger, &cvar) != 2 || cvar != '\n') && clean_stdin()));
}

void CreatArr(uint8_t *ptr, uint8_t arrsize)
{
    uint8_t count = 0;
    
    for( count = 0; count < arrsize; count++)
    {
        printf("ptr[%hhu] = ",count);
        t_uscanf((ptr+count));
    }
}
void PrintArr(uint8_t *ptr, uint8_t arrsize)
{
    uint8_t count = 0;
    
    for( count = 0; count < arrsize; count++)
    {
        printf("ptr %hhu = %hhu\n",count, *(ptr+count));
    }
}



/*******************************************************************************
*                                EOF
*******************************************************************************/
