#include <iostream>
using namespace std;

int main ()
{

    int a = 10;
    int b = 5;
    cout << "a is: " << a << endl;
    cout << "b is: " << b << endl;
    cout << endl;
    
    a = a+b;
    b = a - b;
    a = a-b;

//numbers are swapped

    cout << "new a is: " << a << endl;
    cout << "new b is: " << b << endl;

    return  0;
}