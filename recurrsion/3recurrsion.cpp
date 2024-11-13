#include <iostream>
using namespace std;

//print N to 1, n times using recurrsion.
void printrevnum(int n)
{
    if (n < 1) return;
    else 
    {
        cout << n << endl;
    }
    printrevnum(n-1);
}
int main ()
{

    int n;
    cout << "enter the number of times: ";
    cin >> n;
    printrevnum(n);

    return 0;
}