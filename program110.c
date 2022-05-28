// SINGLY LINEAR LINKED LIST
/*
    InsertFirst
    InsertLast
    InsertAtPosition
    DeleteFirst
    DeleteLast
    DeleteAtPosition
    Display
    Count
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;
/*
    * allocate memory for node.
    * initialize the node .
    * check whether LL is empty or not.
    * if LL is empty the new node is the first node.
    * if LL contains atleast one node in it the store the address
      of privious first node int the next pointer of new node.

*/
void InsertFirst(PPNODE Head, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if (*Head == NULL) // if LL is empty
    {
        *Head = newn;
    }
    else // if LL contains atleast one node
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void Display(PNODE Head)
{
    printf("\n");
    while (Head != NULL)
    {
        printf("%d\t", Head->data);
        Head = Head->next;
    }
    printf("\n");
}

int main()
{
    PNODE First = NULL;

    InsertFirst(&First, 101);
    InsertFirst(&First, 51);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);

    Display(First);

    return 0;
}

/*  RULES

    1. Use only dynamic memory allocation
    2. dont write any technical syntax in main
    3. Dont use any global variables
    4. Be careful while manipulating the first pointer
    5. pass the first pointer directly if the function is not going
       to modify the LL (Display,count)
    6.pass the address of firsst pointer if the function is going to modify
      the LL.

*/