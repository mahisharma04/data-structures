#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class queue
{
    private:
        Node* start;
        Node* end;
        int Qsize;

    public:
        queue()
        {
            start = nullptr;
            end = nullptr;
            Qsize = 0;
        }

        void enqueue(int val)
        {
            Node* newNode = new Node();
            newNode->data = val;
            newNode->next = nullptr;

            if(start == nullptr && end == nullptr)
            {
                start = end = newNode;
            }
            else
            {
                end->next = newNode;
                end = newNode;
            }
            cout << "Node is inserted." << endl;
        }

        void dequeue()
        {
            if(start == nullptr)
            {
                cout << "The queue is empty.";
                return;
            }

            Node* temp = start;
            start = start->next;
            if(start == nullptr)
            {
                end = nullptr;
            }

            delete temp;
            return;
            
        }

        
};