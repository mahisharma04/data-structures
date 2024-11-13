#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class Stack
{
    private:
        Node* top; int size;
        
    public:
        Stack()
        {
            top = nullptr;
            size = 0;
        }

        void printstack()
        {
            if(top == nullptr)
            {
                cout << "stack is empty.";
                return;
            }

            Node* current = top;
            while(current != nullptr)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

        void push(int val)
        {
            Node* newNode = new Node();
            newNode->data = val;
            newNode->next = top;
            top = newNode;
            size++;
        }

        void pop()
        {
            if(top == nullptr)
            {
                cout << "Stack is empty!" << endl;
                return;
            }

            Node* temp = top;
            top = top->next;
            delete temp;
            size--;
        }

        int topp()
        {
            if(top == nullptr)
            {
                cout << "Stack is empty!" << endl;
                return -1;
            }
            return top->data;
        }

        int sizee()
        {
            return size;
        }
};

int main()
{
    Stack s;

    s.push(20);
    s.push(10);
    s.push(30);

    int count = s.sizee();
    cout << count << endl;

    s.printstack();
}
