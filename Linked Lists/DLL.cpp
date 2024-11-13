#include <iostream>
#include <vector>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* back;

    //constructor
    node(int data1, node* next1, node* back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    node(int data2)
    {
        data = data2;
        next = nullptr;
        back = nullptr;
    }
    
};

node* convertArray2DLL(vector<int> &arr)
{
    node* head = new node (arr[0], nullptr, nullptr);
    node* prev = head;

    for(int i = 1; i < arr.size(); i++)
    {
        node* temp = new node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

int countnodes(node* head)
{
    if(head == nullptr) return 0;
    int count = 0;
    while(head != nullptr)
    {
        count++;
        head = head->next;
    }
    return count;
}

void printlinkedlist( node* head)
{
    if(head == nullptr) return;
    while ( head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

node* removehead(node* head)
{
    if(head == nullptr) return nullptr;
    if(head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    node* temp = head;

    head = temp->next;
    head->back = nullptr;
    delete temp;
    return head;
}

node* removetail(node* head)
{
    if(head == nullptr) return nullptr;
    if(head->next == nullptr)
    {
        delete head;
        return nullptr;
    }
    node*temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->back->next = nullptr;
    delete temp;
    return head;
}

node* removeposition(node* head, int k)
{
    if(head == nullptr) return nullptr;
    int count = countnodes(head);
    if(k < 1 || k > count)
    {
        cout << "invalid position...returning head" << endl;
        return head;
    }
    if(k == 1) return removehead(head);
    if(k == count) return removetail(head);

    node* temp = head;
    int cnt = 1;
    while(cnt<k)
    {
        temp = temp->next;
        cnt++;
    }
    temp->back->next = temp->next;
    temp->next->back = temp->back;
    delete temp;
    return head;
    
}

node* inserthead(node* head, int val)
{
    if(head == nullptr) return new node(val);
    node* newNode = new node(val, head, nullptr);
    head->back = newNode;
    return newNode;
}

node* inserttail(node*head, int val)
{
    if(head==nullptr) return new node(val);

    node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }

    node* newNode = new node(val,nullptr, temp);
    temp->next = newNode;
    return head;
}

node* insertposition(node* head , int val , int k)
{
    if(head == nullptr) return new node(val);
    int count = countnodes(head);
    if(k < 1 || k > count+1)
    {
        cout << "invalid position." << endl;
        return head;
    }
    if(k==1) return inserthead(head, val);
    if(k==count+1) return inserttail(head, val);

    int cnt = 1;
    node* temp = head;
    while(temp != nullptr)
    {
        cnt++;
        if(cnt == k) break;
        temp = temp->next; //temp is at one node before the kth node.
    }

    node* newNode = new node(val, temp->next, temp);
    temp->next = newNode;
    newNode->next->back = newNode;
    return head;
    
}

void insertbeforenode(node* givenode , int val)
{
    node* back = givenode->back;
    node* newNode = new node(val, givenode, back );
    back->next = newNode;
    givenode->back = newNode;
}

node* reverselinkedlist(node* head)
{
    //to reverse a linkedlist swap the next and back pointers and return the new head.
    if(head == nullptr) return nullptr;

    node* temp = nullptr;
    node* current = head;

    while(current != nullptr)
    {
        temp = current->back;
        current->back = current->next;
        current->next = temp;
        current = current->back;
    }
    return (temp->back);
}

int main ()
{

    vector<int> vec = {10,20,30,40};
    node* head = convertArray2DLL(vec);

    printlinkedlist(head);

    head = reverselinkedlist(head);

    printlinkedlist(head);




    return 0;
}