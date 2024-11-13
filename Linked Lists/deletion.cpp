#include <iostream>
#include <vector>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int data1, node* next1)
    {
        data = data1;
        next = next1;
    }

    node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

node* convertArr2LL(vector<int> &arr)
{
    node* head = new node(arr[0]);
    node* mover = head;

    for(int i = 1; i<arr.size(); i++)
    {
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;

}

void printlinkedlist(node* head)
{
    if(head == nullptr) return;
    node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int countnodes(node* head)
{
    if(head == nullptr) return 0;
    int cnt = 0;
    node* temp = head;
    while(temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

node* removehead(node* head)
{
    if(head == nullptr) return head;
    node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

node* removetail(node* head)
{
    if(head == nullptr || head->next == nullptr) return nullptr; //in case there is no node or only one node.
    node* temp = head;

    while(temp->next->next != nullptr) //to reach the second last node
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head;
}

node* removeposition(node* head, int k)
{
    if(head == nullptr) return nullptr;
    if(k==1) return removehead(head); //case if k is the first element
    int count = countnodes(head);
    if(k==count) return removetail(head); //case if k is the last element
    if(k < 1 || k > count) return head;

    node* prev = nullptr;
    node* temp = head;

    int cnt = 1;
    while(cnt != k)
    {
        prev = temp;
        temp = temp->next;
        cnt++;
    }

    prev->next = temp->next;
    delete temp;
    return head;
    
}

node* inserthead(node* head, int val)
{
    node* temp = new node(val,head);
    return temp;
}

node* inserttail(node*head , int val)
{
    node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    node* element = new node(val);
    temp->next = element;
    return head;
}

node* insertposition(node* head, int val, int k)
{
    int count = countnodes(head);
    if(k < 1 || k > count+1) return head;

    if(k==1) return inserthead(head, val);
    if(k==count+1) return inserttail(head, val);

    int cnt = 1;
    node* temp = head;

    while(cnt < k-1)
    {
        temp = temp->next;
        cnt++;
    }

    node* newNode = new node(val,temp->next);
    temp->next = newNode;

    return head;
}

node* reverselinkedlist(node*head)
{
    node*prev = nullptr;
    node* current = head;
    node* next = nullptr;

    while(current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main ()
{

    vector<int> vec = {11,3,5,7,9};
    node* head = convertArr2LL(vec);

    // cout << head->data << endl;

    head = removetail(head);

    printlinkedlist(head);

    head = removeposition(head, 5);
    printlinkedlist(head);

    head = inserthead(head,60);
    head = inserthead(head, 70);
    head = inserttail(head, 100);
    printlinkedlist(head);

    head = insertposition(head, 400 , 4);
    printlinkedlist(head);

    head = reverselinkedlist(head);
    printlinkedlist(head);

    



    

    return 0;
}