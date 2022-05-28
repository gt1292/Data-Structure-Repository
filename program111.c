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

void InsertFirst(PPNODE head, int no)
{
    // Allocate memory for node(dynamically)
    // initialize node

    // check LL is empty or not
    // LL is empty then new node is first node so update its address in first pointer through head

    // if Ll is not empty then store the address of first node int the next pointer of our new node
    // update the first pointer through head
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if (*head == NULL) // LL is empty
    {
        *head = newn;
    }
    else // LL contain at least one node
    {
        newn->next = *head;
        *head = newn;
    }
}

void Display(PNODE head)
{
    printf("elements from linked list :\n");
    while(head != NULL)
    {
        printf("|%d|->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int Count(PNODE head)
{
    int iCnt = 0;

    while(head != NULL)
    {
        iCnt++;
        head = head->next;
    }
    return iCnt;
}

void InsertLast(PPNODE head, int no)
{
    // Allocate memory for node(dynamically)
    // initialize node

    // check LL is empty or not
    // LL is empty then new node is first node so update its address in first pointer through head

    // if Ll is not empty then travel till last node of LL
    //store the address of new node in the next pointer of last node
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if (*head == NULL) // LL is empty
    {
        *head = newn;
    }
    else // LL contain at least one node
    {
       //code
    }
}

int main()
{
    int iRet = 0;

    PNODE first = NULL;

    InsertFirst(&first, 101);
    InsertFirst(&first, 51);
    InsertFirst(&first, 21);
    InsertFirst(&first, 11);

    Display(first);

    iRet = Count(first);
    printf("number of elements are: %d",iRet);


    return 0;
}