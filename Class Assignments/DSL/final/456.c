#include <stdio.h>
struct node{
    int data;
	struct node* next;
	};
	struct node* addNode (int data) {
	struct node* newNode = (struct node*)malloc(sizeof(struct
	node));
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode;
	}
 
struct node* display (struct node* head) { struct node* temp = head;
printf("The Linked List is: "); while (temp != NULL) {
printf("%d -> ", temp -> data); temp = temp -> next;
}
printf("NULL\n");
}

struct node* insertAtBeginnning (struct node* head, int data) { struct node* newNode = addNode(data);
newNode -> next = head; return newNode;
}

struct node* insertAtEnd(struct node* head, int data) { struct node* newNode = addNode(data);
if (head == NULL) { return newNode;
}
struct node* temp = head; while (temp -> next != NULL) {
temp = temp -> next;
}
temp -> next = newNode; return newNode;
}

struct node* insertAtPosition (struct node* head, int data, int position) {
struct node* newNode = addNode(data); if(position == 1) {
head = newNode -> next; return newNode;
}
struct node* temp = head;
for (int i = 1; i < position - 1 && temp != NULL; i++) { temp = temp -> next;
}
if (temp != NULL) {
printf("Position is out of bounds.\n"); free(newNode);
return head;
}
 
	else {
newNode -> next = temp -> next; temp -> next = newNode;
}
return head;
}

struct node* deleteAtBeginning (struct node* head) { struct node* temp = head;
if(head == NULL) {
printf("The Linked List is Empty.\n"); return head;
}
else {
head = head -> next; free(temp);
return head;
}
}

struct node* deleteAtEnd (struct node* head) { if (head == NULL) {
printf("the list is empty.\n");
}

}








#include <stdio.h> #include <stdlib.h>

struct Node {
int data;
struct Node* prev; struct Node* next;
};

struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 
newNode->data = data; newNode->prev = NULL; newNode->next = NULL; return newNode;
}

void displayList(struct Node* head) { struct Node* temp = head; printf("Doubly Linked List: "); while (temp != NULL) {
printf("%d ", temp->data); temp = temp->next;
}
printf("\n");
}

struct Node* insertAtBeginning(struct Node* head, int data) { struct Node* newNode = createNode(data);
if (head == NULL) { head = newNode;
} else {
newNode->next = head; head->prev = newNode; head = newNode;
}
return head;
}

struct Node* insertAtEnd(struct Node* head, int data) { struct Node* newNode = createNode(data);
if (head == NULL) { head = newNode;
} else {
struct Node* temp = head; while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newNode; newNode->prev = temp;
}
return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int position) {
 
struct Node* newNode = createNode(data); if (position == 1) {
head = insertAtBeginning(head, data); return head;
}
struct Node* temp = head;
for (int i = 1; i < position - 1 && temp != NULL; i++) { temp = temp->next;
}
if (temp == NULL) {
printf("Position out of bounds\n");
}
else {
newNode->next = temp->next; newNode->prev = temp;
if (temp->next != NULL) {
temp->next->prev = newNode;
}
temp->next = newNode;
}
return head;
}

struct Node* deleteFromBeginning(struct Node* head) { if (head == NULL) {
printf("List is empty\n"); return head;
}
struct Node* temp = head; head = head->next;
if (head != NULL) { head->prev = NULL;
}
free(temp); return head;
}

struct Node* deleteFromEnd(struct Node* head) { if (head == NULL) {
printf("List is empty\n"); return head;
}
struct Node* temp = head; if (temp->next == NULL) {
free(temp);
 
return NULL;
}
while (temp->next != NULL) { temp = temp->next;
}
temp->prev->next = NULL; free(temp);
return head;
}

struct Node* deleteFromPosition(struct Node* head, int position)
{
if (head == NULL) { printf("List is empty\n"); return head;
}
struct Node* temp = head; if (position == 1) {
head = deleteFromBeginning(head); return head;
}
for (int i = 1; i < position && temp != NULL; i++) { temp = temp->next;
}
if (temp == NULL) {
printf("Position out of bounds\n");
}
else {
if (temp->next != NULL) {
temp->next->prev = temp->prev;
}
if (temp->prev != NULL) {
temp->prev->next = temp->next;
}
free(temp);
}
return head;
}

int main() {
struct Node* head = NULL; int pos1;
printf("enter the position of the node you want to delete:
\n");
scanf("%d", &pos1);
 
	
head = insertAtEnd(head, 10); head = insertAtEnd(head, 20); head = insertAtEnd(head, 30); displayList(head);

head = insertAtBeginning(head, 5); displayList(head);

head = insertAtPosition(head, 25, 3); displayList(head);

head = deleteFromBeginning(head); displayList(head);

head = deleteFromEnd(head); displayList(head);

head = deleteFromPosition(head, pos1); displayList(head);

return 0;
}





#include <stdio.h> #include <stdlib.h>

// Define the structure for a node struct Node {
int data;
struct Node* next;
};

// Function to create a new node struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = newNode; // Points to itself to make it circular
return newNode;
 
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head, int data) { struct Node* newNode = createNode(data);
if (*head == NULL) {
*head = newNode;
} else {
struct Node* temp = *head; while (temp->next != *head) {
temp = temp->next;
}
temp->next = newNode; newNode->next = *head;
*head = newNode;
}
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int data) { struct Node* newNode = createNode(data);
if (*head == NULL) {
*head = newNode;
} else {
struct Node* temp = *head; while (temp->next != *head) {
temp = temp->next;
}
temp->next = newNode; newNode->next = *head;
}
}

// Function to delete a node with a specific value void deleteNode(struct Node** head, int key) {
if (*head == NULL) return;

struct Node *temp = *head, *prev = NULL;

// If head node itself holds the key to be deleted if (temp->data == key && temp->next == *head) {
*head = NULL; free(temp);
 
return;
}

// If the head needs to be deleted and the list has more than one node
if (temp->data == key) {
while (temp->next != *head) { temp = temp->next;
}
temp->next = (*head)->next; free(*head);
*head = temp->next; return;
}

// Search for the node to be deleted
while (temp->next != *head && temp->data != key) { prev = temp;
temp = temp->next;
}

// If the node to be deleted was found if (temp->data == key) {
prev->next = temp->next; free(temp);
}
}

// Function to display the circular linked list void displayList(struct Node* head) {
if (head == NULL) { printf("List is empty.\n"); return;
}
struct Node* temp = head; do {
printf("%d -> ", temp->data); temp = temp->next;
} while (temp != head); printf("(head)\n");
}

// Main function int main() {
struct Node* head = NULL;
 
	
// Insert nodes at the beginning insertAtBeginning(&head, 10);
insertAtBeginning(&head, 20);
insertAtBeginning(&head, 30);

printf("Circular Linked List after inserting at the beginning:\n");
displayList(head);

// Insert nodes at the end insertAtEnd(&head, 40);
insertAtEnd(&head, 50);

printf("Circular Linked List after inserting at the end:\n");
displayList(head);

// Delete a node deleteNode(&head, 20);
printf("Circular Linked List after deleting a node:\n"); displayList(head);

return 0;
}
