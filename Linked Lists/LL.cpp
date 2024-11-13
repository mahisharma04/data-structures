#include <iostream>
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

void printlinkedlist(node* head)
{
    while(head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void sortlinkedlist(node* head)
{
    if(head == nullptr)
    {
        cout << "empty linked list.";
        return;
    }

    for(node* i = head; i->next != nullptr; i = i->next)
    {
        node* minIndex = i;
        for(node* j = i; j!=nullptr; j = j->next)
        {
            if(j->data < minIndex->data)
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {
            int temp = minIndex->data;
            minIndex->data = i->data;
            i->data = temp;
        }
    }
}

int countnodes(node* head)
{
    int cnt = 0;
    while( head != nullptr)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

node* inserthead(node* head, int val)
{
    if (head == nullptr) return new node(val);

    node* newNode = new node(val, head);
    head = newNode;
    return head;
}

node* inserttail(node* head, int val)
{
    if(head == nullptr) return new node(val);

    node* temp = head;
    node* newNode = new node(val);
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

node* insertposition(node* head, int val, int k)
{
    int n = countnodes(head);
    if(k < 1 || k > n+1 )
    {
        cout << "invalid position." << endl;
        return head;
    }

    if(head == nullptr) return new node(val);
    if(k == 1) return inserthead(head, val);
    if(k == n+1 ) return inserttail(head, val);
    else
    {
        node* temp = head;
        int counter = 0;
        while(temp != nullptr)
        {
            temp = temp->next;
            counter++;
            if( counter == k-2)
            {
                break;
            }
        }

        node* newNode = new node(val, temp->next);
        temp->next = newNode;
        return head;
    }
}

int main()
{

    node* head = nullptr;

    head = inserttail(head, 80);
    head = inserthead(head, 40);
    head = inserthead(head, 20);
    head = inserttail(head, 15);
    head = inserttail(head, 90);
    head = insertposition(head, 100, 5);

    sortlinkedlist(head);



    printlinkedlist(head);


    return 0;
}