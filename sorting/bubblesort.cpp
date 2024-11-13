#include <iostream>
using namespace std;

//Step 1: locate the biggest element in the array and push it to last by swapping adjacent elements;
//Step 2: Repeat the process

//tip: No need to look at the last set of sorted elements as we know the biggest elements have already been pushed to the last.

//Time Complexity is O(n^2) in Worst and Average cases but O(N) which is linear in best case.
//how? : As if in the first interation of the outer for loop only if there are no swaps that are being done then we simply break out of the for loop hence O(N).

void bubblesort(int array[], int n)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n-i-1; j++)
        {
            if(array[j] > array [j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main ()
{

    int n;
    cout << "enter the number of elements that you want in the array: ";
    cin >> n;

    int array[100];

    cout << "enter the elements:-\n";
    for (int i =0; i<n; i++) cin >> array[i];

    cout << "sorting array..." << endl;

    bubblesort(array,n);

    cout << "printing array...";
    for (int i = 0; i<n; i++)
    {
        cout << array[i] << ", ";
    }

    return 0;
}