#include<iostream>
#include<vector>
using namespace std;

int ls (vector<int> &vec, int n)
{
    cout << "enter your target: ";
    int target;
    cin >> target;

    for(int i = 0; i < n; i++)
    {
        if(vec[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    int n;
    cout << "enter the number of elements that you want in your array: ";
    cin >> n;

    vector<int> vec(n);

    cout << "enter elements in your array: ";
    for(int i = 0; i<n; i++) cin >> vec[i];

    int index = ls(vec,n);

    if(index == -1) cout << "element not found in the array.";
    else cout << "element found at index: " << index;



    return 0;
}