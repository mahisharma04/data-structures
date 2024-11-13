#include <iostream>
#include <vector>
using namespace std;

//MergeSort : algorithm based on dividing and merging the array to sort the elements. TIME COMPLEXITY lesser than bubble/insertion/selection sort
// TC --> O(N log N)

void merge (vector<int> &arr , int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while (left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low; i<=high; i++)
    {
        arr[i] = temp[i-low];
    }
    
}

void mergesort (vector<int> &arr, int low, int high)
{
    if (low >= high) return;
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid+1, high);
    merge(arr, low, mid, high);

}

int main()
{

    int n;
    cout << "enter the number of elements:-\n";
    cin >> n;
    vector<int> array(n);

    for(int i = 0 ; i<n; i++) cin >> array[i];

    cout << "sorting array...\n";
    mergesort(array, 0, n-1);

    cout << "printing sorted array...";
    for(int i = 0 ; i < n ; i++) cout << array[i] << ", ";

    return 0;
}