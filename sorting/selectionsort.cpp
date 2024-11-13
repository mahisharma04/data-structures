#include <iostream>
using namespace std;

//Step 1: Select the minimum element of the array and swap it with the first element.
//Step 2: continue the process for the remaining unsorted array.

//tip : for the inner loop j = i because there is no use of looking at the full array again and again, only starting from the index of the unsorted array will suffice.

//Time Complexity is O(n^2) in all 3 cases [best, avg, worst].

void selectionsort(int array[], int n)
{
    for(int i = 0; i<n; i++)
    {
        int min = i;
        for(int j = i; j<n; j++)
        {
            if(array[j] < array[min])
            {
                min = j;
            }
        }
        int temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
}


int main()
{

    int n;
    cout << "enter the number of elements that you want in the array: ";
    cin >> n;

    int array[100];
    cout << "enter the elements:-\n";

    for(int i = 0 ; i<n; i++) cin >> array[i];

    cout << "sorting array...\n";
    selectionsort(array, n);

    cout << "printing sorted array...";
    for(int i = 0 ; i < n ; i++) cout << array[i] << ", ";


    return 0;
}