#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "enter your number: ";
    cin >> n;

    int mul = 1;

    while (n>0)
    {
        mul = mul*n;
        n--;
    }

    cout << "the result is: " << mul;

    return 0;
}