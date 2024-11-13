#include<stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
//representing the head and tail of the singly linked list.
struct node *head, *tail = NULL;

//addnode() will add a new node to the list
void addnode(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> next = NULL;

    //checking if the list is empty
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail -> next = newnode;
        tail = newnode;
    }
}

void addNodeAtBeginning(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;

    // If the list was empty, update the tail to the new node
    if (tail == NULL) {
        tail = newnode;
    }
}

void addNodeAtEnd(int data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL; // This should be NULL because it will be the new tail node

    if (tail == NULL)
    { // If the list is empty, update both head and tail
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}

int countNodes() {
    int count = 0;
    struct node *current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}


void display()
{
    //node current will point to head.
    struct node * current = head;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Nodes of singly linked list: \n");
    while(current != NULL)
    {
        //Prints each node by incrementing pointer
        printf("%d\n", current -> data);
        current = current -> next;
    }
    printf("\n");
}

int main ()
{
    //adding nodes
    addnode(40);
    addnode(2);
    addnode(3);
    addnode(4);
    addnode(10);

    //to display the nodes
    display();

    printf("\n");
    addNodeAtEnd(120);
    addNodeAtBeginning(99);

    int count = countNodes();

    

    display();
    printf("\n");
    printf("Number of nodes are : %d", count);
    return 0;
}
