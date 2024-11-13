#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* addtoempty(struct node* head, int data)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

struct node* addtobegin(struct node* head , int data)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = head;

    if(head != NULL) head->prev = temp;

    head = temp;

    return head;
}

struct node* addtoend(struct node* head, int data)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if(head == NULL)
    {
        temp->prev = NULL;
        head = temp;
        return head;
    }

    struct node* mover = head;
    while(mover->next != NULL)
    {
        mover = mover->next;
    }

    mover->next = temp;
    temp->prev = mover;

    return head;
}

struct node* addatposition(struct node* head, int position, int data)
{
    if(position == 0) return addtobegin(head,data); //if position is given as beginning

    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;

    struct node* current = head;
    int count = 0;

    while(current != NULL && count < position-1)
    {
        current = current->next;
        count++;
    }

    temp->next = current->next;
    temp->prev = current;

    if(current->next != NULL)
    {
        current->next->prev = temp;
    }
    current->next = temp;
    return head;


}

void printlinkedlist(struct node* head)
{
    if(head == NULL) return;
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main ()
{
    struct node* head = NULL;

    head = addtoempty(head,45);
    head = addtobegin(head, 20);
    head = addtobegin(head, 5);
    head = addtobegin(head, 10);
    //add a traversal() function as well

    printlinkedlist(head);

    head = addtoend(head,100);

    printlinkedlist(head);

    head = addatposition(head, 3 , 150);

    printlinkedlist(head);


    return 0;
}