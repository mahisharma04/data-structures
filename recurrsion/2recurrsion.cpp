#include <iostream>
using namespace std;

// printing 1 to N , n times using recurrsion.

void printnum(int i,int n)
{
    if (i>n) return;
    else
    {
        cout << i << endl;
    }
    printnum(i+1, n);

}

int main()
{

    int n;
    cout << "enter the number of times: ";
    cin >> n;
    printnum(1,n);
    return 0;
}