/*=================================================================================================
*                                        Include
* system and project includes
* needed interfaces from external units
* internal and external interfaces from this unit
=================================================================================================*/
#include "func.h"


int main() 
{
/*=================================================================================================
*                                      Static variables
=================================================================================================*/
    static uint8_t s_character;
    static uint8_t s_arr[MAX_SIZE] = {0};
    static uint8_t s_arrsize = 0;
    static uint8_t s_active = 1;
    /* if s_active = 1 then loop program else out program*/ 

/*=================================================================================================
*                                       Code
=================================================================================================*/
    Tutorial(); 

    while (s_active)
    {
        printf("\nEnter your selection: ");
        fflush(stdin);
        scanf("%c",&s_character);
        
        switch (s_character){
            case 'c':
            case 'C':
                printf("How many elements in Array? ");
                t_uscanf(&s_arrsize);
                /* scanf("%"SCNu8,&s_arrsize); */
                CreatArray(s_arr, s_arrsize);
                break;
            case 'p':
            case 'P':
                PrintArray(s_arr, s_arrsize);
                break;
            case 'i':
            case 'I':
                AddElement(s_arr, &s_arrsize);
                break;
            case 'd':
            case 'D':
                DeleteElement(s_arr, &s_arrsize);
                break;
            case 's':
            case 'S':
                IncreaseArrange(s_arr,s_arrsize);
                break;
            case 'x':
            case 'X':
                DecreaseArrange(s_arr,s_arrsize);
                break;
            case 't':
            case 'T':
                FindElement(s_arr,s_arrsize);
                break;
            case 'a':
            case 'A':
                PrintMaxValue(s_arr,s_arrsize);
                break;
            case 'w':
            case 'W':
                PrintMinValue(s_arr,s_arrsize);
                break;
            case 'r':
            case 'R':
                system("cls"); /* Clear console windows */
                Tutorial();
                break;
            case 'e':
            case 'E':
                printf("\nExit Program");
                getch();
                s_active = 0; 
                break;
            default:
                 printf("\nPlease Reinput");
                 break;
        }
    }
    printf("\nGoodbye!!!");
    return 0;
}

