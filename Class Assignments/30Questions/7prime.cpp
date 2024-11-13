#include <iostream>
#include <cmath>
using namespace std;

int prime(int n)
{
    
    for (int i=2; i < n; i++)
    {
        if(n%i == 0)
        return 0;
    }
    return 1;

}

int main()
{

    int n;
    cout << "enter your number: ";
    cin >> n;

    int is_prime = prime(n);
    if(is_prime) cout << "the number is a prime number";
    else cout << "the number is not a prime number";
    return 0;
}