/*!*****************************************************************************
* @file            pointer.h
* @brief           Header for pointer.c
* @author          ThangNC23
* @deadline        24/08/21
*******************************************************************************/

#ifndef _POINTER_H_
#define _POINTER_H_


/*******************************************************************************
*                                Include
*******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

/*******************************************************************************
*                                  API
*******************************************************************************//*


/*!*****************************************************************************
* @function       allocate10Bytes
* @brief          allocate for pointer
* @para[i]        a pointer
* @return         true if allocate sucess, else return false
*******************************************************************************/
bool allocate10Bytes(uint8_t *outPtr);

/*!*****************************************************************************
* @function       t_uscanf
* @brief          Not allow input characters
* @para[i]        uint8_t pointer
* @return         void
* @description    Only allow input intenger, if input is character then retype
*******************************************************************************/
void t_uscanf(uint8_t* pintenger);

/*!*****************************************************************************
* @function       CreatArray
* @brief          Creat new array
* @para[i]        Array
* @para[i]        Size of array
* @return         void
*******************************************************************************/
void CreatArr(uint8_t *, uint8_t);

/*!*****************************************************************************
* @function       PrintArray
* @brief          Print array to console windows
* @para[i]        Array
* @para[i]        Size of array
* @return         void
*******************************************************************************/
void PrintArr(uint8_t *, uint8_t);


#endif /* _FUNC_H_ */
