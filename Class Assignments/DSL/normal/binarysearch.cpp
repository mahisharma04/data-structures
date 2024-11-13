#include <iostream>
using namespace std;

int binarysearch(int array[] , int n , int target)
{
    int low = 0;
    int high = n-1;
    while (low < high)
    {

        int mid = (low + high) / 2;

        if(array[mid] == target) return mid;
        else if(target < array[mid]) high = mid-1;
        else if(target > array[mid]) low = mid + 1;
        else
        {
            return -1;
        }
    }

    // for(int i = low; i<high; i++)
    // {
    //     int mid = (low + high) / 2;

    //     if(array[mid] == target) return mid;
    //     else if(target < array[mid]) high = mid-1;
    //     else if(target > array[mid]) low = mid + 1;
    //     else
    //     {
    //         return -1;
    //     }
    // }
}

int main ()
{

    int arr[100];
    int n;

    cout << "how many elements do you want in your array: ";
    cin >> n;

    cout << "enter elements (SORTED) in your array:- " << endl;
    for(int i = 0; i<n; i++) cin >> arr[i];

    int target;
    cout << "enter your target element:";
    cin >> target;

    int result = binarysearch(arr,n,target);

    if(result == -1) cout << "element not found";
    else cout << "element found at index: " << result;

    return 0;
}