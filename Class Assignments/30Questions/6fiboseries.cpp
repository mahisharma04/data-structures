#include <iostream>
using namespace std;

int fibo(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    else 
    {
        return (fibo(n-1) + fibo(n-2));
    }
}

int main ()
{

    cout << "enter number: ";
    int n;
    cin >> n;

    int result = fibo(n);
    cout << "result is: " << result;
    return 0;
}