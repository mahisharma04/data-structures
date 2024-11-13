#include<iostream>
using namespace std;

//printing N to 1, n times using backtracking.
void printrevnum(int i, int N)
{
    if(i>N) return;
    else{
        printrevnum(i+1, N);
        cout << i;
    }
}

int main ()
{

    int n;
    cout << "enter the number of times: ";
    cin >> n;

    printrevnum(1, n);
    return 0;
}