#include <iostream>
using namespace std;

//using parametric form:

void factorial(int n, int product)

{
    if (n == 1) 
    {
        cout << product;
        return;
    }
    else
    {
        factorial(n-1 , product * n); 
    }
}

//using functional approach: 

int fact(int n)
{
    if ( n == 1 || n == 0) return 1;
    else return(n * fact(n-1));
}
int main ()
{

    int n;
    cout << "enter the number of which you want the factorial of: ";
    cin >> n;
    factorial(n,1);
    // cout << fact(n);
    return 0;
}