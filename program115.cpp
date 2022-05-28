#include <iostream>

using namespace std;

#define True 1
#define False 0

typedef int BOOL;

struct node
{
    int data;
    node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class Singly_linkedlist
{
private:
    PNODE head;

public:
    Singly_linkedlist();
    ~Singly_linkedlist();
    BOOL insert_First(int);
    BOOL insert_Last(int);
    BOOL InsertAtPosition(int, int);
    inline void Display();
    inline int Count();
    BOOL DeleteFirst();
    BOOL DeleteAtPosition(int);
    BOOL DeleteLast();
};

Singly_linkedlist ::Singly_linkedlist()
{
    head = NULL;
}

Singly_linkedlist ::~Singly_linkedlist()
{
    PNODE Temp, Navigate;

    if (head != NULL)
    {
        Navigate = head;
        while (Navigate != NULL)
        {
            Temp = Navigate->next;
            delete Navigate;
            Navigate = Temp;
        }
    }
}

BOOL Singly_linkedlist::insert_First(int no)
{
    PNODE newn = NULL;
    newn = new NODE;

    if (newn == NULL)
    {
        return False;
    }

    newn->next = NULL;
    newn->data = no;

    if (head == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head = newn;
    }
    return True;
}

BOOL Singly_linkedlist ::insert_Last(int no)
{
    PNODE newn = NULL, temp = head;
    newn = new NODE;

    if (newn == NULL)
    {
        return False;
    }

    newn->next = NULL;
    newn->data = no;

    if (head == NULL)
    {
        head = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    return True;
}

BOOL Singly_linkedlist ::InsertAtPosition(int pos, int no)
{
    if ((head == NULL) || (pos > Count() + 1) || (pos <= 0))
    {
        return False;
    }

    if (pos == 1)
    {
        return (insert_First(no));
    }
    else if (pos == (Count()) + 1)
    {
        return (insert_Last(no));
    }
    else
    {
        PNODE newn = NULL, temp = head;

        newn = new NODE;

        if (newn == NULL)
        {
            return False;
        }

        newn->next = NULL;
        newn->data = no;

        for (int i = 1; i <= (pos - 2); i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
    return True;
}

BOOL Singly_linkedlist::DeleteAtPosition(int pos)
{
    if ((head == NULL) || (pos > Count()) || (pos <= 0))
    {
        return False;
    }
    else if (pos == 1)
    {
        DeleteFirst();
    }
    else if (pos == (Count()))
    {
        DeleteLast();
    }
    else
    {
        PNODE temp1 = head, temp2 = NULL;

        for (int i = 1; i <= (pos - 2); i++)
        {
            temp1 = temp1->next;
            ++i;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;

        delete temp2;
    }
    return True;
}

BOOL Singly_linkedlist::DeleteFirst()
{
    PNODE temp = head;

    if (head == NULL)
    {
        return False;
    }
    else
    {
        head = head->next;
        free(temp);
    }
    return True;
}
BOOL Singly_linkedlist::DeleteLast()
{
    if (head == NULL)
    {
        return False;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        PNODE temp1 = head, temp2 = NULL;

        while (temp1->next->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = NULL;
        free(temp2);
    }
    return True;
}

void Singly_linkedlist ::Display()
{
    PNODE temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int Singly_linkedlist ::Count()
{
    PNODE temp = head;
    int iCnt = 0;

    while (temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

int main()
{
    Singly_linkedlist obj1;
    Singly_linkedlist *obj2 = new Singly_linkedlist();

    obj1.insert_First(51);
    obj1.insert_First(21);
    obj1.insert_First(11);

    obj1.InsertAtPosition(75, 2);
    obj1.Display();
    cout << "Number of Nodes :" << obj1.Count() << endl;

    obj1.DeleteFirst();
    obj1.Display();

    obj1.DeleteLast();
    obj1.Display();

    obj2->insert_First(501);
    obj2->insert_First(511);
    obj2->insert_First(521);

    obj2->Display();

    obj2->insert_Last(551);
    obj2->InsertAtPosition(601, 3);

    obj2->Display();

    cout << "Number of Nodes :" << obj2->Count() << endl;

    delete obj2;

    return 0;
}