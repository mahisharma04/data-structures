#include <iostream>
using namespace std;

int binarysearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n-1;
    

    while(low <= high)
    {
        int mid = (low+high)/2;
        if(target == arr[mid]) return mid;

        if(target< arr[mid]) high = mid - 1;
        if(target > arr[mid]) low = mid + 1; 
    }
}
int main()
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

    int result = binarysearch(arr,n,target);

    cout << "The element is present at index: " << result;

    return 0;
}