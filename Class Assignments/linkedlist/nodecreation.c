#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};

int main ()
{

    struct node* head;
    head = malloc(sizeof(struct node));
    head -> data = 67;
    head -> link = NULL;
    struct node* ptr = malloc(sizeof(struct node));
    ptr -> data = 98;
    ptr -> link = NULL;

    struct node* ptr1 = malloc(sizeof(struct node));
    ptr1 -> data = 31;
    ptr1 -> link = NULL;


    head->link = ptr;
    ptr->link = ptr1;
    
    printf("%p\n", head->link);
    printf("%p\n", ptr);




//head->next = ptr; ptr -> next = ptr1; ptr1 -> next = ptr2; and so on... 

    return 0;
}