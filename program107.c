#include<stdio.h>
#include<stdlib.h>

//structure declaration
struct node
{
    int data;   //4
    struct node *next;  //8
};

typedef struct node NODE;

int main()
{
    //static memory allocation
    NODE obj;

    //Dynamic memory allocation
    NODE *ptr = (NODE *)malloc(sizeof(NODE));

    obj.data = 11;  //Direct accessing operator
    obj.next = NULL;

    ptr->data = 11; //indirect accessing operator
    ptr->next = NULL;

    return 0;
}