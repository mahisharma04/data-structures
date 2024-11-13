#include <iostream>
using namespace std;

int binarysearch(int array[] , int n , int target) //iterative
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
}

int RecursiveBinarySearch(int array[] , int low , int high , int target) //recursive
{
    if(low > high) return -1; //base condition

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

    int target; //entering the element you want to find
    cout << "enter your target element:";
    cin >> target;

    cout << "------MENU-----" << endl; //building menu for selection
    cout << "1. Binary Search (iterative)\n2. Binary Search (recursive)" << endl << endl;
    
    int options; //for the switch case
    cout << "Choose your desired option: ";
    cin >> options;

    int result;
    switch(options)
    {
        case 1:
        {
            result = binarysearch(arr,n,target); //iterative
            break;
        }

        case 2:
        {
            result = RecursiveBinarySearch(arr,0,n,target); //recursive
            break;
        }
        default:
            cout << "Please choose a valid option!" << endl;
            break;
    }

    if(result == -1) cout << "The element was not found in the array.";
    else cout << "element found at index: " << result;
    return 0;
}