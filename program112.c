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
    while (head != NULL)
    {
        printf("|%d|->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int Count(PNODE head)
{
    int iCnt = 0;

    while (head != NULL)
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
    // store the address of new node in the next pointer of last node
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if (*head == NULL) // LL is empty
    {  
        *head = newn;
    }
    else // LL contain at least one node
    {
        // travel till last node
        // store the address of new node in the next pointer of last node
        temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE head)
{
    // if LL is emty then return
    // if LL contain atleast one node then 
    // store the address of second node

    PNODE temp = NULL;

    if (*head == NULL)
    {
        return;
    }
    else // LL contain atleast one node
    {
        temp = *head;
        *head = temp->next;
        free(temp);
    }
}

void DeleteLast(PPNODE head)
{
    // if LL is empty then return
    // if LL contain one node then delete that node and return
    // if LL contains more than one noce then travel till last node and delete last node
    PNODE temp = NULL;

    if (*head == NULL)
    {
        return;
    }
    else if ((*head)->next == NULL) // LL contains one node
    {
        free(*head);
        *head = NULL;
    }
    else // LL is contains more than one node
    {
        temp = *head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}


void InsertAtPos(PPNODE head,int no,int pos)
{
    //if position is invalid then return directly
    //if position is 1 then call insertfirst
    //if position is N+1 then call insertlast
    
    int size = 0;
    int iCnt = 0;
    size = Count(*head);
    PNODE temp = NULL;

    if((pos<1) || (pos>(size+1)))
    {
        printf("position is invalid\n");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(head,no);
    }
    else if(pos == (size+1))
    {
        InsertLast(head,no);
    }
    else        //At position 
    {
        PNODE newn = NULL;

        newn = (PNODE)malloc(sizeof(NODE));   //newn = (struct node *)malloc(12)

        newn->data = no;
        newn->next = NULL;

        temp = *head;

        for(iCnt =  1; iCnt<pos-1; iCnt++)
        {
            temp = temp ->next;
        }

        newn ->next = temp ->next;  //right hand side
        temp-> next = newn;         //left hand side
    }
}

void DeleteAtPos(PPNODE head,int pos)
{
    //if pos is invalid then return (<1 or >4)
    //if pos is 1 then call deletefirst
    //if pos is N then call deletelast(pos is 4)
    int size = 0;
    int iCnt = 0;
    size = Count(*head);
    PNODE temp = NULL;
    PNODE tempdelete;

    if((pos<1) || (pos>(size)))
    {
        printf("position is invalid\n");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(head);
    }
    else if(pos == size)
    {
        DeleteLast(head);
    }
    else        //At position 
    {
        temp = *head;

        for(iCnt =  1; iCnt<pos-1; iCnt++)
        {
            temp = temp ->next;
        }

        tempdelete = temp ->next;
        temp->next = temp->next->next;
        free(tempdelete);
    }
}

int main()
{
    int iRet = 0;

    PNODE first = NULL;

    InsertFirst(&first, 101); // call by address
    InsertFirst(&first, 51);
    InsertFirst(&first, 21);
    InsertFirst(&first, 11);

    InsertAtPos(&first,75,3);

    DeleteAtPos(&first,3);

    Display(first); // call by value
    iRet = Count(first);
    printf("number of node are: %d\n", iRet);

    InsertFirst(&first, 1);
    iRet = Count(first);
    printf("number of node are: %d\n", iRet);

    InsertLast(&first, 111);
    InsertLast(&first, 121);
    Display(first); // call by value
    iRet = Count(first);
    printf("number of nodes are: %d\n", iRet);

    DeleteFirst(&first);
    Display(first); // call by value
    iRet = Count(first);
    printf("number of nodes are: %d\n", iRet);

    DeleteLast(&first);
    Display(first); // call by value
    iRet = Count(first);
    printf("number of nodes are: %d\n", iRet);

    return 0;
}