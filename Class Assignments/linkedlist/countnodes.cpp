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
};

int main ()
{

    node* a = new node(2,nullptr);


    return 0;
}