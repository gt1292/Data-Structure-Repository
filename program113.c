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

void InsertAtFirst(PPNODE head, int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->next = NULL;
    newn->data = no;

    if (*head == NULL)
    {
        *head = newn;
    }
    else
    {
        newn->next = *head;
        *head = newn;
    }
}

void InsertAtLast(PPNODE head, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->next = NULL;
    newn->data = no;

    if (*head == NULL)
    {
        *head = newn;
    }
    else
    {
        temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void InserAtPos(PPNODE head, int no, int pos)
{
    // Consider no of nodes are 4

    // If position is invalid then return directly (< 1  OR > 5)
    // If position is 1 then call insertfirst
    // If position is N+1 then call Insertlast  (position is 5)

    int size = 0; 
    int iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    size = Count(*head);

    if((pos < 1) || (pos > (size+1)))
    {
        printf("Position is invalid\n");
        return;
    }

    if(pos == 1)
    {
        InsertAtFirst(head,no);
    }
    else if(pos == (size+1))
    {
        InsertAtLast(head,no);
    }
    else        // Logic
    {
        newn = NULL;

        newn = (PNODE)malloc(sizeof(NODE));     // newn = (struct node *)malloc(12);

        newn->data = no;
        newn->next = NULL;

        temp = *head;

        for(iCnt = 1; iCnt < pos-1 ; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp->next = newn;
    }
    
}

void Display(PNODE head)
{
    printf("\nElements from linked list :\n");
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
void DeleteFirst(PPNODE head)
{
    // If LL is empty then return
    PNODE temp = NULL;

    if (*head == NULL)
    {
        return;
    }
    // if LL contain one node then store the address of second node
    else
    {
        temp = *head;
        *head = temp->next;
        free(temp);
    }
}

void DeleteLast(PPNODE head)
{
    PNODE temp = NULL;
    if (*head == NULL)
    {
        return;
    }
    else if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
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
int main()
{
    int Ret = 0;
    PNODE first = NULL;

    // InsertAtFirst function calling
    InsertAtFirst(&first, 101);
    InsertAtFirst(&first, 51);
    InsertAtFirst(&first, 21);
    InsertAtFirst(&first, 11);

    Display(first);
    Ret = Count(first);
    printf("Number of Nodes are :%d", Ret);

    // InsetLAst function call
    InsertAtLast(&first, 111);
    InsertAtLast(&first, 121);
    Display(first);
    Ret = Count(first);
    printf("Number of Nodes are :%d", Ret);

    // Delete First function call
    DeleteFirst(&first);
    Display(first);
    Ret = Count(first);
    printf("Number of Nodes are :%d", Ret);

    // Deletelast function call
    DeleteLast(&first);
    Display(first);
    Ret = Count(first);
    printf("Number of Nodes are :%d\n", Ret);

    //insert at position function call
    InserAtPos(&first,75,2);
    Display(first);
    Ret = Count(first);
    printf("Number of Nodes are :%d\n", Ret);

    return 0;
}