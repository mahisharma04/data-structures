#include<iostream>
//printing Name N times using recurrsion.
using namespace std;
    int count = 0;
int printname(int n)
{
    if(count == n) return 0;
    else
    {
        cout << "name" << endl;
        count += 1;
    }
    printname(n);
}

int main()
{
    int n;
    cout << "enter the number of times: ";
    cin >> n;
    printname(n);


    return 0;
}