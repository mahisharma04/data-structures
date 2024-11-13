#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//QUICK SORT
// 1. Pivot a random element in the array and put it in it's correct place.
//....
//how that can be done is by iterating i that is set on low by i++ till we find element greater than the pivot
//and iterating j that is set on high by j-- till we find element smaller than the pivot
//make sure to add the boundary crossing limitations while doing i++ and j--
//swap the elements after you have gotten i and j but make sure that you swap only when i hasn't crossed j, that is must (i < j) 
// 2. Smaller on the left and larger on the right.
int placement(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < high)
    {
        while ( arr[i] <= pivot && i <= high - 1)  // i <= high - 1 , that is so when we do i++ i dont cross the boundary of the array/vector.
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if(i > j) 
        {
            swap(arr[i] , arr[j]);
        }
        swap(arr[low], arr[j]);
        return j;
        
    }
}
void quicksort(vector<int> &arr, int low, int high)
{
    if(low < high)
    {
        int index = placement(arr,0,arr.size() - 1);
        quicksort(arr,low,index-1);
        quicksort(arr, index+1, high);
    }
}

int main ()
{

    int n;
    cout << "enter the number of elements:-\n";
    cin >> n;
    vector<int> array(n);

    for(int i = 0 ; i<n; i++) cin >> array[i];

    cout << "sorting array...\n";  
    quicksort(array, 0, array.size()-1);

    cout << "printing sorted array...";
    for(int i = 0 ; i < n ; i++) cout << array[i] << ", ";
    
    return 0;
}