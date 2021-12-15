/*!*****************************************************************************
* @file            func.c
* @brief           Define functions
* @author          ThangNC23
* @deadline        20/08/21
*******************************************************************************/

/*******************************************************************************
*                                Include
*******************************************************************************/
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <inttypes.h>

#include "func.h"

/*******************************************************************************
*                               Prototype
*******************************************************************************/

/*!*****************************************************************************
 *@function        swap
* @brief           swap value of two parameters
* @parameters      pval1 and pval2 
* @return          void
*******************************************************************************/
static void swap(uint8_t *pval1, uint8_t *pval2);

/*!*****************************************************************************
* @function        clean_stdin
* @brief           check '\n' for scanf
* @return          1
* @description     this function used for function t_uscanf
*******************************************************************************/
static uint8_t clean_stdin();

/*******************************************************************************
*                               Defination
*******************************************************************************/
void Tutorial(void)
{
    printf("\n********************************************\n");
    printf("Array Management \n");
    printf("\n_ c : Creat an array"); 
    printf("\n_ p : Print array");
    printf("\n_ i : Add an element");
    printf("\n_ d : Delete an element"); 
    printf("\n_ s : Arrange increase");
    printf("\n_ x : Arrange decrease ");
    printf("\n_ t : Find an element");
    printf("\n_ a : Print max value");
    printf("\n_ s : Print min value");
    printf("\n_ r : Clear");
    printf("\n_ e : Exit");
    printf("\n********************************************\n");
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
    }while (((scanf("%"SCNu8"%c", pintenger, &cvar) != 2 || cvar != '\n') && clean_stdin()));
}

void CreatArray(uint8_t arr[], uint8_t arrsize)
{
    uint8_t count = 0;
    
    printf("\n");
    /* Clear Array */
    for(count = 0; count < MAX_SIZE; count++)
    {
        arr[count] = 0;
    }
    /* Input Array */
    for(count = 0; count < arrsize; count++)
    {
        printf("a[%hhu] = ",count);
        t_uscanf(&arr[count]);
        /* scanf("%"SCNu8,&arr[count]); */
    }
}


void PrintArray(uint8_t arr[], uint8_t arrsize)
{
    uint8_t checksum = 0; /* checksum for testing Is array empty? */
    uint8_t count = 0;
    
    for(count = 0; count < MAX_SIZE; count++)
    {
        checksum += arr[count];
    }
    
    /* if Array is empty print empty else print array */
    if(checksum == 0)
    {
        printf("\nEmpty Array");
    }
    else
    {
        printf("Output Array");
        for(count = 0; count < arrsize; count++)
        {
            printf("\narr[%hhu] = %hhu", count, arr[count]);
        }
    }
}

void AddElement(uint8_t arr[], uint8_t *parrsize)
{
    uint8_t element = 0; /* element you want to add */
    uint8_t position = 0; /* position of element */
    uint8_t count = 0;
    
    /* Check condition of position */
    do
    {
        printf("Input position you want to add ");
        t_uscanf(&position);
        /* scanf("%"SCNu8, &position); */
        if((position < 0)||(position > *parrsize))
        printf("Please input 0 <= position <= %hhu \n", *parrsize);
    }
    while((position < 0)||(position > *parrsize));
    
    printf("\nInput the element: ");
    t_uscanf(&element);
    /* scanf("%"SCNu8, &element); */
    
    for(count = *parrsize; count > position; count--)
    {
        arr[count] = arr[count-1];
    }
    arr[position] = element;
    printf("\nAdded %hhu to arr[%hhu] ", element, position);
    ++*(parrsize);
}

void DeleteElement(uint8_t arr[], uint8_t *parrsize)
{
    uint8_t position = 0; /* position you want to delete */
    uint8_t count = 0;
    
    /* check position */
    do
    {
        printf("\nInput position (From 0) that you want to delete: ");
        t_uscanf(&position);
        if((position < 0)||(position >= *parrsize))
        {
            printf("Please input 0 <= position < %hhu", *parrsize);
        }
    }
    while((position < 0)||(position >= *parrsize));
    
    for(count = position; count < *(parrsize)-1; count++)
    {
        arr[count] = arr[count+1];
    }
    printf("Deleted element at posiotion %hhu", position);
    --*(parrsize);
}

void swap(uint8_t *pval1, uint8_t *pval2)
{
    uint8_t temp = 0;
    
    temp = *pval1;
    *pval1 = *pval2;
    *pval2 = temp;
}

void IncreaseArrange(uint8_t arr[], uint8_t arrsize)
{
    uint8_t count = 0;
    uint8_t bigCount = 0;
    uint8_t smallCount = 0;
    uint8_t minNum = 0;
    
    /*  Selection sort */
    for (smallCount = 0; smallCount < arrsize-1; smallCount++)
    {
         minNum = smallCount;
        for (bigCount = smallCount+1; bigCount < arrsize; bigCount++)
        if (arr[bigCount] < arr[minNum])
        minNum = bigCount;
        swap(&arr[minNum], &arr[smallCount]);
    }
    
    printf("\nArray after arrange increase: ");
    for(count=0; count < arrsize; count++)
    {
        printf("\narr[%hhu] = %hhu", count, arr[count]);
    }
}

void DecreaseArrange(uint8_t arr[], uint8_t arrsize)
{
    uint8_t bigCount = 0;
    uint8_t smallCount = 0;
    uint8_t maxNum = 0;
    uint8_t count = 0;
    /* Selection sort */
    for (smallCount = 0; smallCount < arrsize-1; smallCount++)
    {
        maxNum = smallCount;
        for (bigCount = smallCount+1; bigCount < arrsize; bigCount++)
        if (arr[bigCount] > arr[maxNum])
        maxNum = bigCount;
        swap(&arr[maxNum], &arr[smallCount]);
    }
    
    printf("\nArray after arrange decrease: ");
    for(count = 0; count < arrsize; count++)
    {
        printf("\narr[%hhu] = %hhu", count, arr[count]);
    }
}

void FindElement(uint8_t arr[], uint8_t arrsize)
{
    uint8_t timeFound = 0; /* The time element appeared */
    uint8_t element = 0; /* Element you want to find */
    uint8_t count = 0;
    
    printf("Input Element you want to find: ");
    t_uscanf(&element);
    /* scanf ("%"SCNu8, &element); */
    
    /************************************* 
     * if element appear, print position
     * if not print not Found
    *************************************/
    for(count = 0; count < arrsize; count++)
    {
        if (arr[count] == element)
        {
            printf("Found element at arr[%hhu]\n", count);
            timeFound ++;
        }
    }
    if(timeFound == 0){
        printf("\nElement not Found!");
    }
    else
    {
        printf("\nTimes element appear is: %hhu",timeFound);
    }
}

void PrintMaxValue(uint8_t arr[], uint8_t arrsize)
{
    uint8_t maxValue = arr[0];
    uint8_t count = 0;
    
    for(count = 0; count < arrsize; count++)
    {
        if(arr[count] > maxValue)
        maxValue = arr[count];
    }
    printf("\nMax Value in Arr = %hhu", maxValue);
}

void PrintMinValue(uint8_t arr[], uint8_t arrsize)
{
    uint8_t minValue = arr[0];
    uint8_t count = 0;
    
    for(count = 0; count < arrsize; count++)
    {
        if(arr[count] < minValue)
        minValue = arr[count];
    }
    printf("\nMin Value in Arr = %hhu", minValue);
}


/*******************************************************************************
*                                EOF
*******************************************************************************/
