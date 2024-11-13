#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int data;           // Data part of the node
    struct node* next;  // Pointer to the next node
};

// Initialize front and rear pointers for the queue
struct node* front = NULL;
struct node* rear = NULL;


void enqueue(int value) //for enqueue create the memory for the data
{
    struct node* ptr;
    ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = value;
    ptr -> next = NULL;
    if((front == NULL) && (rear == NULL))
    {
        front = rear = ptr;

    }
    else
    {
        rear -> next = ptr;
        rear = ptr;
    }
    printf("Node is Inserted. \n");
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL; // If queue becomes empty
    }

    printf("Node is Deleted: %d\n", temp->data);
    free(temp);
}

void printQueue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    enqueue(30);
    enqueue(50);
    enqueue(40);

    dequeue();

    printQueue();
    return 0;
}