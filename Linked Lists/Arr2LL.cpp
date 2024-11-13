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


int main()
{

    vector<int> arr = {2,5,7,10,11};

    node* head = convertArr2LL(arr);

    // cout << head->data << endl; //commented for code purpose (CFC)

    //traversing in the Linked List
    node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}