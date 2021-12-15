/*!*****************************************************************************
* @file           list.h
* @brief          Header file for list.c
* @author         ThangNC23
*******************************************************************************/
#ifndef _LIST_H_
#define _LIST_H_

/*******************************************************************************
*                                  Include
*******************************************************************************/
#include <stdint.h>
#include <stdio.h>

/*******************************************************************************
*                                 Definations
*******************************************************************************/
/* Number students of the class */
#define SIZE_OF_CLASS 31U

/* Max of score = 10 */
#define MAX_SCORE     10U

/* Max of id = 999 */
#define MAX_ID        999U

/* Color for set background console */
#define BLACK         0U
#define GREEN         2U
#define AQUA          3U
#define RED           4U
#define PURPLE        5U
#define YELLOW        6U


/*******************************************************************************
*                                  Typedef
*******************************************************************************/
/* Structure of linked list */
typedef struct t_node {
    uint8_t name[20];
    uint16_t id;
    uint8_t score;
    struct t_node *next;
} node;

typedef struct t_node *pnode;

/*******************************************************************************
*                                 Variables
*******************************************************************************/
/* Array to save data of Students */
extern node ListStudent[SIZE_OF_CLASS];

/*******************************************************************************
*                                    API
*******************************************************************************/
/**
* @brief          Input intenger number type uint8_t,if input is character then retype
* @param[in]      Uint8_t pointer (address of variable)
* @param[out]     Value of variable
* @return         No
*/
void u8scanf(uint8_t *pintenger);

/**
* @brief          Input intenger number type uint16_t
* @param[in]      Uint8_t pointer (address of variable)
* @param[out]     Value of variable
* @return         No
* @description    Input 16bit - intenger, if input is character then retype
*/
void u16scanf(uint16_t *pintenger);

/**
* @brief          Description functions of program
* @param[in]      No
* @param[out]     No
* @return         No
*/
void DisplayFunction(void);

/**
* @brief          Add new node
* @param[in]      Head of List
* @param[out]     No
* @return         head
*/
pnode AddNewNode(pnode head);

/**
* @brief          Delete a node
* @param[in]      Head of List
* @param[out]     No
* @return         head
*/
pnode DeleteNode(pnode head);

/**
* @brief          Init new list with 31 students of class
* @param[in]      head: head of list, ListStudent: Array ListStudent defined
* @param[out]     No
* @return         head
*/
pnode InitLinkedList(pnode head, pnode ListStudent);

/**
* @brief          Creat new list
* @param[in]      No
* @param[out]     No
* @return         head of new list
*/
pnode Input(void);

/**
* @brief          Print List
* @param[in]      Head of list
* @param[out]     No
* @return         No
*/
void PrintList(pnode head);

/**
* @brief          Find with ID
* @param[in]      Head of list
* @param[out]     No
* @return         No
*/
void Find(pnode head);

/**
* @brief          Color for display
* @param[in]      background_color, text_color
* @param[out]     No
* @return         No
*/
void SetColor(uint8_t background_color, uint8_t text_color);

/**
* @brief          Set cursor to position x,y
* @param[in]      x: x coordinate, y: y coordinate
* @param[out]     No
* @return         No
*/
void gotoxy(uint8_t x, uint8_t y);

/**
* @brief          Get y coordinate
* @param[in]      void
* @param[out]     No
* @return         y coordinate of cursor
*/
uint8_t wherey(void);

/**
* @brief          Get x coordinate
* @param[in]      void
* @param[out]     No
* @return         x coordinate of cursor
*/
uint8_t wherex(void);



#endif /* _LIST_H_ */



/*******************************************************************************
*                                     EOF
*******************************************************************************/
