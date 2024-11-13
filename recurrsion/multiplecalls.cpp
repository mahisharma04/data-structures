#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

//doing fibonacci number using multiple recursion calls, the thing to learn here is multiple recursion calls.

int fibo(int n)
{
    if (n <= 1) return n;
    int last = fibo(n-1);          //1st recursion call
    int secondlast = fibo(n-2);   //2nd recursion call 
    return last + secondlast;
}

int main()
{

    int n;
    cout << "enter the fibonacci term: ";
    cin >> n;
    cout << "answer: " << fibo(n);

    return 0;
}