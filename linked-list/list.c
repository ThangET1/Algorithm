/*!*****************************************************************************
* @file           func.c
* @brief          Definations for list.h
* @author         ThangNC23
*******************************************************************************/

/*******************************************************************************
*                                  Include
*******************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "list.h"

/*******************************************************************************
*                                   Variables
*******************************************************************************/
/* List students of class */
node ListStudent[SIZE_OF_CLASS] = {
                    {"AnhPT54", 1, 8, NULL},
                    {"BachTV", 2, 8, NULL},
                    {"BangTX", 3, 8, NULL},
                    {"BaoVQ5", 4, 8, NULL},
                    {"ChienND8", 5, 8, NULL},
                    {"DatNT162", 6, 8, NULL},
                    {"DuongNT62", 7, 8, NULL},
                    {"HanhNTH8", 8, 8, NULL},
                    {"HoaLK3", 9, 8, NULL},
                    {"HoangTHM", 10, 8, NULL},
                    {"HungDD8", 11, 8, NULL},
                    {"HuongPTT12", 12, 8, NULL},
                    {"HuongTT20", 13, 8, NULL},
                    {"LongNH58", 14, 8, NULL},
                    {"MinhBQ4", 15, 8, NULL},
                    {"MinhPC9", 16, 8, NULL},
                    {"PhanDD", 17, 8, NULL},
                    {"PhuongNQT", 18, 8, NULL},
                    {"QuangTM12", 19, 8, NULL},
                    {"QuangTM13", 20, 8, NULL},
                    {"QuyenNT27", 21, 8, NULL},
                    {"QuyetCV1", 22, 8, NULL},
                    {"ThachHS", 23, 8, NULL},
                    {"ThangNC23", 24, 8, NULL},
                    {"ThinhPQ3", 25, 8, NULL},
                    {"ThoPN", 26, 8, NULL},
                    {"TienTA3", 27, 8, NULL},
                    {"TuanND53", 28, 8, NULL},
                    {"TuND17", 29, 8, NULL},
                    {"TungBT14", 30, 8, NULL},
                    {"TungVT11", 31, 8, NULL},
                    };

/*******************************************************************************
*                               Prototype
*******************************************************************************/
/**
* @brief          Used for func init list
* @param[in]      head: head of list, ListStudent: Data of one student
* @param[out]     No
* @return         head
*/
static pnode AddTailToInitList(pnode head, node ListStudent);

/**
* @brief          Creat new node use for Add functions
* @param[in]      head
* @param[out]     No
* @return         New node
*/
static pnode CreatNode(pnode head);

/**
* @brief          check '\n' for scanf
* @param[in]      No
* @param[out]     No
* @return         1 if type '\n'
* @description    this function used for function u8scanf
*/
static uint8_t clean_8stdin();

/**
* @brief          Check '\n' for scanf
* @param[in]      No
* @param[out]     No
* @return         1 if type '\n'
* @description    This function used for function u16scanf
*/
static uint16_t clean_16stdin();


/*******************************************************************************
*                                   Code
*******************************************************************************/
static uint8_t clean_8stdin(void)
{
    /* Warning is yellow */
    SetColor(BLACK, YELLOW);
    printf("Intenger please: ");
    SetColor(BLACK, AQUA);
    while (getchar() != '\n')
    {
    }
    
    return 1;
}

static uint16_t clean_16stdin(void)
{
    /* Warning is yellow */
    SetColor(BLACK, YELLOW);
    printf("Intenger please: ");
    SetColor(BLACK, AQUA);
    while (getchar() != '\n')
    {
    }
    
    return 1;
}

void u8scanf(uint8_t *pintenger)
{
    uint8_t cvar;
    
    do
    {
        /* do not nothing */
    } while(((scanf("%hhu%c", pintenger, &cvar) != 2)||(cvar != '\n'))&&clean_8stdin());
}

void u16scanf(uint16_t *pintenger)
{
    uint8_t cvar;
    
    do
    {
        /* do not nothing */
    } while(((scanf("%hu%c", pintenger, &cvar) != 2)||(cvar != '\n'))&&clean_16stdin());
}

void DisplayFunction(void)
{
    /* Set cursor to position (x, y) = (0, 0) */
    gotoxy(0,0);
    printf("1. P: Print List Student ");
    printf("\n2. A: Add Student ");
    printf("\n3. D: Delete Student ");
    printf("\n4. F: Find Student with ID ");
    printf("\n5. E: Exit ");
    printf("\n-----------------------------------------");
}

static pnode CreatNode(pnode head)
{
    pnode new_node = NULL;
    pnode ptr = head;
    uint8_t IdOK = 1;
    
    new_node = (pnode)malloc(sizeof(struct t_node));
    /* Check NULL for new_node */
    while(new_node == NULL)
    {
        printf("\n-----Allocated Failded-----");
        new_node = (pnode)malloc(sizeof(struct t_node));
    }
    /* Input ID */
    do
    {
        IdOK = 1; /* if id is invalid-->IdOK = 0 */
        printf("----ID:    ");
        u16scanf(&new_node->id);
        for(ptr = head; ptr!= NULL; ptr = ptr->next)
        {
            if ((new_node->id == ptr->id)&&(0 <= new_node->id <= MAX_ID))
            {
                SetColor(BLACK, RED);
                printf("ID existed!\n");
                SetColor(BLACK, AQUA);
                IdOK = 0;
            }
            else
            {
                /* do nothing */
            }
            
        }
        if ((new_node->id < 1)||(new_node->id > MAX_ID))
        {
            printf("ID is number beetween 0 and 999!!!\n");
            IdOK = 0;
        }
        else
        {
            /* do nothing */
        }
    } while (IdOK == 0);
    /* Input Name */
    printf("----Name:  ");
    scanf("%s", new_node->name);
    /* Input Score */
    do
    {
        printf("----Score: ");
        u8scanf(&new_node->score);
        if ((new_node->score < 0)||(new_node->score > MAX_SCORE))
        {
            printf("Score is between 0 and 10. Retype!!!\n");
        }
    } while ((new_node->score < 0)||(new_node->score > MAX_SCORE));
    new_node->next = NULL;
    
    return new_node; /* Return new node had data */
}

pnode AddNewNode(pnode head)
{
    int16_t position = 0;
    uint16_t count = 0;
    uint16_t success = 0;/* If add success then printf to the screen */
    pnode ptr = head;
    pnode new_node = NULL;

    do
    {
        printf("Input position : ");
        u16scanf(&position);
        if ((position <= 0)||(position > MAX_ID))
        {
            printf("Position is between 1 and 999\n");
        }
    } while ((position <= 0)||(position > MAX_ID));
    if((head == NULL) || (position == 1|0))
    {
        new_node = CreatNode(head);
        new_node->next = head;
        head = new_node;
        success = 1;
    }
    else
    {
        /* Find position */
        count = 2;
        /* ptr start from head == position 0 of list
                    --> count start from 2        */
        ptr = head;
        while(ptr->next != NULL && count != position)
        {
            ptr = ptr->next;
            ++count;
        }
        if((count != position))
        {
            /* Set color and print announce */
            SetColor(BLACK, RED);
            printf("Position must < length list = %d\n",count - 1);
            SetColor(BLACK, YELLOW);
            printf("If you want add tail, input %d\n",count);
            SetColor(BLACK, AQUA);
        }
        else
        {
            /* add node to list */
            new_node = CreatNode(head);
            new_node->next = ptr->next;
            ptr->next = new_node;
            success = 1; /* success = 1--> print to screen */
        }
    }
    printf("----------------------------------------\n");
    if(success == 1)
    {
        SetColor(BLACK, GREEN);
        printf("Added student to position %d\n",position);
        printf("Type P to print new List!!\n");
        SetColor(BLACK, AQUA);
    }
    else
    {
        /* do nothing */
    }
    
    return head;
}

static pnode AddTailToInitList(pnode head, node ListStudent)
{
    uint16_t count = 0;
    pnode ptr = NULL;
    pnode new_node = NULL;
    
    new_node = (pnode)malloc(sizeof(struct t_node));
    /* Check NULL for new_node */
    while(new_node == NULL)
    {
        printf("\n-----Allocated Failded-----");
        new_node = (pnode)malloc(sizeof(struct t_node));
    }
    /* Copy data from array ListStudent */
    for(count = 0; count < sizeof(ListStudent.name); count++)
    {
        new_node->name[count] = ListStudent.name[count];
    }
    new_node->id = ListStudent.id;
    new_node->score = ListStudent.score;
    new_node->next = ListStudent.next;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        ptr = head;
        while (ptr -> next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    
    return head;
}

pnode InitLinkedList(pnode head, pnode ListStudent)
{
    uint16_t count = 0;
    
    for(count = 0; count < SIZE_OF_CLASS; count++)
    {
        head = AddTailToInitList(head, ListStudent[count]);
    }
    
    return head;
}

pnode DeleteNode(pnode head)
{
    pnode ptr = head;
    pnode pre = head;
    uint16_t ID = 0;
    uint16_t Deleted = 0;
    uint16_t count = 0;
    
    printf("Input ID to delete: ");
    u16scanf(&ID);
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        ++count;
        if ((ptr->id == ID) && (count == 1))
        {
            head = head->next;
            SetColor(BLACK, YELLOW);
            printf("Deleted at ID %d", ID);
            printf("\nInfo: %d----%s----%d",ptr-> id, ptr->name, ptr->score);
            SetColor(BLACK, GREEN);
            printf("\nType P to print new List!!\n");
            SetColor(BLACK, AQUA);
            Deleted = 1;
        }
        else if (ptr->id == ID)
        {
            pre->next = pre->next->next;
            SetColor(BLACK, YELLOW);
            printf("Deleted at ID %d", ID);
            printf("\nInfo: %d----%s----%d",ptr-> id, ptr->name, ptr->score);
            SetColor(BLACK, GREEN);
            printf("\nType P to print new List!!\n");
            SetColor(BLACK, AQUA);
            Deleted = 1;
        }
        else
        {
            /* do nothing */
        }
        pre = ptr;
    }
    if(Deleted == 0)
    {
        SetColor(BLACK, RED);
        printf("\nID not found");
        SetColor(BLACK, AQUA);
    }
    else
    {
        /* do nothing */
    }
    
    return head;
}

void Find(pnode head)
{
    pnode ptr = head;
    uint16_t ID = 0;
    uint16_t count = 0;
    uint16_t Found = 0;
    
    printf("Input ID to find: ");
    u16scanf(&ID);
    for (ptr = head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->id == ID)
        {
            SetColor(BLACK, GREEN);
            printf("Found student at position %d", count + 1);
            printf("\nInfo: %d----%s----%d",ptr-> id, ptr->name, ptr->score);
            SetColor(BLACK, AQUA);
            Found = 1;
        }
        else
        {
            /* do nothing */
        }
        ++count;
    }
    if(Found == 0)
    {   
        SetColor(BLACK, RED);
        printf("\nStudent not found");
        SetColor(BLACK, AQUA);
    }
    else
    {
        /* do nothing */
    }
}

void PrintList(pnode head)
{
    uint8_t pos_cur_x = 60;
    uint8_t pos_cur_y = 0;
    uint16_t quantity = 0;
    uint8_t quantityPosition_y = 0;
    pnode ptr = NULL;
    
    /* update position of List Student */
    pos_cur_y = wherey();
    /* go to position updated and print list */
    gotoxy(pos_cur_x,pos_cur_y);
    SetColor(BLACK, YELLOW);
    printf("*************LIST STUDENT************\n");
    /* update position of quantity */
    quantityPosition_y = wherey();
    printf("\n\n");
    pos_cur_y = wherey();
    gotoxy(pos_cur_x,pos_cur_y);
    printf("ID          Name                  Score\n\n");
    SetColor(BLACK, AQUA);
    for(ptr = head; ptr != NULL; ptr = ptr->next)
    {
        pos_cur_y = wherey();
        gotoxy(pos_cur_x, pos_cur_y);
        printf("%-5d", ptr->id);
        printf("\t%-20s", ptr->name);
        printf("\t%-3d\n", ptr->score);
        ++quantity;
    }
    /* go to position of quantity and print */
    gotoxy(pos_cur_x, quantityPosition_y);
    SetColor(BLACK, YELLOW);
    printf("QUANTITY = %d",quantity);
    SetColor(BLACK, AQUA);
}

/* Funtion set color for background console */
void SetColor(uint8_t background_color, uint8_t text_color)
{
    uint8_t color_code = 0;
    HANDLE hStdout = NULL;
    
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    color_code = background_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

/* Funtion set cursur for set background */
void gotoxy(uint8_t x, uint8_t y)
{
    static HANDLE  h = NULL;
    
    if(!h)
    {
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    }
    COORD c = {x,y};
    SetConsoleCursorPosition(h,c);
}

/* Funtion gety used for set background */
uint8_t wherey(void)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    
    return csbi.dwCursorPosition.Y;
}

/* Funtion gety used for set background */
uint8_t wherex(void)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    
    return csbi.dwCursorPosition.X;
}

/*******************************************************************************
*                                   EOF
*******************************************************************************/
