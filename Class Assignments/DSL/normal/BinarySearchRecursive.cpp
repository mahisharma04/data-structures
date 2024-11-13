#include <iostream>
using namespace std;

int RecursiveBinarySearch(int array[] , int low , int high , int target)
{
    if(low > high) return -1;

    int mid = (low + high) / 2;
    
    if(array[mid] == target) return mid;
    else if(target > array[mid]) return RecursiveBinarySearch(array, mid+1 , high , target);
    else if(target < array[mid]) return RecursiveBinarySearch(array, low, mid-1, target);
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

    int result = RecursiveBinarySearch(arr , 0 , n-1 , target);

    if(result == -1) cout << "element not found";
    else cout << "element found at index: " << result;   

    return 0;
}