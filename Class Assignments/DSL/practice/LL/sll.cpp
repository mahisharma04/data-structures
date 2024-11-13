#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node() : data(0), next(nullptr) {}
    node(int data1, node* next1) : data(data1), next(next1) {}
    node(int data1) : data(data1), next(nullptr) {}

};

void printLinkedList(node* head){
    if(head == nullptr){
        cout << "The linked list is empty.";
        return;
    }

    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int countNodes(node* head){

    if(head == nullptr) return 0;

    int cnt = 0;
    while(head != nullptr){
        cnt++;
        head = head->next;
    }
    return cnt;
}

node* reverseLinkedList(node*head){
    if(head == nullptr) return nullptr;

    node* prev = nullptr;
    while(head != nullptr){
        node* temp = head;
        head = head->next;
        temp->next = prev;
        prev = temp;
    }
    return prev;
}

node* insert(node* head, int val){
    if(head == nullptr) return new node(val);

    node* temp = head;
    while(temp->next != nullptr) temp = temp->next;
    
    node* newNode = new node(val);
    temp->next = newNode;

    return head;
}

node* insertHead(node* head, int val){
    if(head == nullptr) return new node(val);

    node* newNode = new node(val, head);
    return newNode;
}

node* insertPosition(node* head, int val, int pos){
    if(head == nullptr) return new node(val);

    node* temp = head;
    int cnt = 1;
    int count = countNodes(head);

    if(pos == 1) return insertHead(head, val);
    else if(pos > count+1){
        cout << "please retry with a valid entry." << endl;
        return head;
    }

    while(cnt < pos - 1){
        temp = temp->next;
        cnt++;
    }

    node* newNode = new node(val);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

int main(){
    node* head = nullptr;
    head = insert(head, 50);
    head = insert(head, 60);
    head = insert(head, 45);
    head = insert(head, 55);
    head = insertHead(head, 70);
    head = insertPosition(head, 100, 5);

    printLinkedList(head);

    node* reversedHead = reverseLinkedList(head);

    printLinkedList(reversedHead);


    return 0;
}
