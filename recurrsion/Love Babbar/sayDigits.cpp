#include <iostream>
using namespace std;

void sayDigit(int n, string arr[])
{
    //Base Case
    if(n == 0) return;
    
    //processing
    int digit = n % 10;
    n = n/10;

    //recursive call
    sayDigit(n, arr);

    cout << arr[digit] << " ";
}

int main()
{
    int n;
    cin >> n;

    string arr[10] = {"Zero", "one","Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    sayDigit(n, arr);
    return 0;
}