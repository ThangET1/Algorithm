/*!*****************************************************************************
* @file           func.h
* @brief          Header file for function.c
* @author         ThangNC23
* @deadline       20/08/21
*******************************************************************************/
#ifndef _HEADER_FUNC_
#define _HEADER_FUNC_

/*******************************************************************************
*                                Include
*******************************************************************************/
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <inttypes.h>

/*******************************************************************************
*                                Definations
*******************************************************************************/
#define MAX_SIZE 100
#define SCNu8 "hhu"

/*******************************************************************************
*                                 API
*******************************************************************************/

/*!*****************************************************************************
* @function       t_uscanf
* @brief          Not allow input characters
* @para[i]        uint8_t pointer
* @return         void
* @description    Only allow input intenger, if input is character then retype
*******************************************************************************/
void t_uscanf(uint8_t* pintenger);

/*!*****************************************************************************
* @function       Tutorial
* @brief          Description functions of program
* @para           void
* @return         void
*******************************************************************************/
void Tutorial(void);

/*!*****************************************************************************
* @function       CreatArray
* @brief          Creat new array
* @para[i]        Array
* @para[i]        Size of array
* @return         void
*******************************************************************************/
void CreatArray(uint8_t arr[], uint8_t arrsize);

/*!*****************************************************************************
* @function       PrintArray
* @brief          Print array to console windows
* @para[i]        Array
* @para[i]        Size of array
* @return         void
*******************************************************************************/
void PrintArray( uint8_t arr[], uint8_t arrsize);

/*!*****************************************************************************
* @function       AddElement
* @brief          Add an element to array
* @para[i]        Array
* @para[i]        Size of array type pointer
* @return         void
* @description    Add to any position < arrsize
*******************************************************************************/
void AddElement(uint8_t arr[], uint8_t *parrsize);

/*!*****************************************************************************
* @function       DeleteElement
* @brief          Delete an element in array
* @para[i]        Array
* @para[i]        Size of array type pointer
* @return         void
* @description    Delete at any position < arrsize
*******************************************************************************/
void DeleteElement(uint8_t arr[], uint8_t *parrsize);

/*!*****************************************************************************
* @function       IncreaseArrange
* @brief          Arrange elements increase
* @para[i]        Array
* @para[i]        Size of array
* @return         void
*******************************************************************************/
void IncreaseArrange(uint8_t arr[], uint8_t arrsize);

/*!*****************************************************************************
* @function       DecreaseArrange
* @brief          Arrange elements decrease
* @para[i]        Array
* @para[i]        Size of array
* @return         void
*******************************************************************************/
void DecreaseArrange(uint8_t arr[], uint8_t arrsize);

/*!*****************************************************************************
* @function       FindElement
* @brief          Find an element in array
* @para[i]        Array
* @para[i]        Size of array
* @return         void
* @description    Print to screen position and appearance times 
*******************************************************************************/
void FindElement(uint8_t arr[], uint8_t arrsize);


/*!*****************************************************************************
* @function       PrintMaxValue
* @brief          Print max value in array to screen
* @para[i]        Array
* @para[i]        Size of array
* @return         void
*******************************************************************************/
void PrintMaxValue(uint8_t arr[], uint8_t arrsize);

/*!*****************************************************************************
* @function       PrintMinValue
* @brief          Print min value in array to screen
* @para[i]        Array
* @para[i]        Size of array
* @return         void
*******************************************************************************/
void PrintMinValue(uint8_t arr[], uint8_t arrsize);

#endif  /* _HEADER_FUNC_ */


/*******************************************************************************
*                                EOF
*******************************************************************************/
