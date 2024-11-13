#include <iostream>
using namespace std;

int linearsearch(int arr[], int n, int target)
{
    for(int i = 0; i<n; i++)
    {
        if(arr[i] == target) return i;
    }
}

int main ()
{

    int n;
    cout << "enter the number of elements that you want in your array: ";
    cin >> n;

    int arr[100];
    for(int i = 0; i<n; i++)
    {
        cout << "Enter element " << i+1 << " : ";
        cin >> arr[i];
    }
    cout << endl;

    int target;
    cout << "Enter the element that you want to search for: ";
    cin >> target;

    int result = linearsearch(arr,n,target);

    cout << "The element is present at index: " << result;


    return 0;
}