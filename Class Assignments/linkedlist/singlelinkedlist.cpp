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
    if(head == nullptr)
    {
        cout << "The linked list is empty.";
        return;
    }
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
    while(head != nullptr)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void sortlinkedlist_asc(node* head)
{
    for(node* i = head; i->next != nullptr; i = i->next)
    {
        node* minIndex = i;
        for(node* j = i->next; j != nullptr; j=j->next)
        {
            if(j->data < minIndex->data)
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {

            int temp = i->data;
            i->data = minIndex->data;
            minIndex->data = temp;
        }
    }
    
}

void sortlinkedlist_dsc(node* head)
{
    for(node* i = head; i->next != nullptr; i = i->next)
    {
        node* minIndex = i;
        for(node* j = i->next; j != nullptr; j=j->next)
        {
            if(j->data > minIndex->data)
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {

            int temp = i->data;
            i->data = minIndex->data;
            minIndex->data = temp;
        }
    }
    
}

node* insertnode_head(node* head, int data)
{
    if(head == nullptr) return new node(data);
    node* temp = new node(data, head);
    return temp;
}

node* mergelinkedlist(node* head1, node* head2)
{

    node* temp = head1;
    while(temp->next != nullptr)
    {
        temp = temp->next; //now we are standing at the last node of head1 linked list
    }

    temp->next = head2; //connect the two linked lists


    return head1;
}



int main()
{

    node* head = new node(10);
    node* head2 = new node(100);

    head = insertnode_head(head, 20);
    head = insertnode_head(head, 50);
    head = insertnode_head(head, 40);
    head2 = insertnode_head(head2, 400);
    head2 = insertnode_head(head2, 300);

    printlinkedlist(head2);

    sortlinkedlist_asc(head2);

    printlinkedlist(head2);

    cout << "-------------------\n";

    printlinkedlist(head);
    sortlinkedlist_dsc(head);
    printlinkedlist(head);

    //merging two linkedlists

    cout << "---------merging-------\n";

    node* merged_linked_list = mergelinkedlist(head2,head);
    printlinkedlist(merged_linked_list);

    cout << "-------sorting final linked list----------\n";

    sortlinkedlist_asc(merged_linked_list);
    printlinkedlist(merged_linked_list);



    return 0;
}