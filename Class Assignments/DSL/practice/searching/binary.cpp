#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int target){

    if(low > high) return -1;

    int mid = (low + high) / 2;
    if(target == arr[mid]) return mid;
    else if(target > arr[mid]) return binarySearch(arr, mid+1, high, target);
    else if(target < arr[mid]) return binarySearch(arr, low, mid-1, target);
}

int main(){
    int arr[100];
    cout << "number of elements in the array: ";
    int n;
    cin >> n;

    cout << "insert elements in the array:-\n";
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    cout << "what element do you want to search for: ";
    int target;
    cin >> target;

    int position = binarySearch(arr, 0, n, target);
    if(position == -1){
        cout << "element not found in the array." << endl;
    }
    else{
        cout << "element found at index: " << position;
    }
    return 0;
}