//used for calculating gcd has a reduced time complexity of O(log_phi min(a,b)), worst case O(log)
//euclidean algo -> gcd(a,b) == gcd (a%b , b) provided that a>b


#include<iostream>
using namespace std;

int hcf(int a, int b)
{
    while(b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main()
{
    int a,b;
    cout << "enter first integer: "; cin >> a; cout << "enter second integer: "; cin >> b;
    int gcd = hcf(a,b);
    cout << "the gcd of " << a << " and " << b << " is: " << gcd;


    return 0;
}