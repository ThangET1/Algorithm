/*!*****************************************************************************
* @file           main.c
* @author         ThangNC23
* @from           FPT Software
*******************************************************************************/

/*******************************************************************************
*                                  Include
*******************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "list.h"

/******************************************************************************/
int main()
{
    pnode head = NULL;
    static uint8_t s_character = ' ';
    static uint8_t s_active = 1;
    
     /* Set tittle and color for program */
    SetConsoleTitle("STUDENT MANAGEMENT");
    SetColor(BLACK, AQUA);
    /* Init Linked List */
    head = InitLinkedList(head,ListStudent);
    PrintList(head);
    DisplayFunction();
    while (s_active)
    {
        SetColor(BLACK, PURPLE);
        printf("\nENTER YOUR SELECTION: ");
        SetColor(BLACK, AQUA);
        fflush(stdin);
        scanf("%c",&s_character);
        switch (s_character)
        {
            case 'a':
            case 'A':
                head = AddNewNode(head);
                break;
            case 'd':
            case 'D':
                head = DeleteNode(head);
                break;
            case 'f':
            case 'F':
                Find(head);
                break;
            case 'p':
            case 'P':
                system("cls");
                PrintList(head);
                DisplayFunction();
                SetColor(BLACK, GREEN);
                printf("\nPrinted List!");
                SetColor(BLACK, AQUA);
                break;
            case 'e':
            case 'E':
                printf("\nGOOD BYE !!!");
                s_active = 0;
                break;
            default:
                 printf("Please Reinput");
                 break;
        }
    }
    
    return 0;
}

