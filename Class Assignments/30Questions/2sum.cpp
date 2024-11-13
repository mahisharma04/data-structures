#include <iostream>
using namespace std;

int addition(int a, int b)
{
    return a+b;
}

int main()
{
    int num1, num2;
    cout << "enter number 1: ";
    cin >> num1;
    cout << "enter number 2: ";
    cin >> num2;

    int result = addition(num1,num2);

    cout << "the resultant value is: " << result;
    return 0;

}