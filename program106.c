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
    struct node obj;

    //Dynamic memory allocation
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    obj.data = 11;  //Direct accessing operator
    obj.next = NULL;

    ptr->data = 11; //indirect accessing operator
    ptr->next = NULL;

    return 0;
}