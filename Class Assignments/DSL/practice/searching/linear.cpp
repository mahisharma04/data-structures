#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target){
    for(int i = 0; i<n; i++){
        if(arr[i] == target) return i;
    }
    return -1;
}

int main()
{

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

    int position = linearSearch(arr, n , target);
    if(position == -1){
        cout << "element not found in the array." << endl;
    }
    else{
        cout << "element found at index: " << position;
    }

    return 0;
}