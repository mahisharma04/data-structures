#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

void arrayreverse(int i, int arr[], int n)

{
     
    if (i>=n/2) return;
    swap(arr[i], arr[n-1-i]);
    arrayreverse(i+1, arr, n);
}
void arrayrev(int l, int r, int arr[])
{
    if (l >= r) return;
    swap(arr[l], arr[r]);
    arrayrev(l+1, r-1, arr);
}
int main()
{
    int n;
    cout << "enter the size of the array: ";
    cin >> n;
    int array[n];

    cout << "enter elements into the array:" << endl;
    for(int i = 0; i<n; i++) cin >> array[i];

    cout << "printing the array: [";
    for(int i = 0; i<n; i++) cout << array[i] << ", ";
    cout << "]\n";

    cout << "reversing array...\n";
    arrayrev(0,n-1,array);
    cout << "printing reversed array: [";
    for(int i = 0; i<n; i++) cout << array[i] << ", ";
    cout << "]";
    return 0;
}