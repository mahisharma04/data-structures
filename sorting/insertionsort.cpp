#include <iostream>
using namespace std;

//Step 1: takes an element and places it in the right order towards the left, by comparing it with each element towards the left.
//Step 2: repeat the process by incrasing the area of the array covered that is incrementing i.

void insertionsort(int array[], int n)
{
    for(int i = 0; i<n; i++)
    {
        int flag = 0;
        for(int j = i; j>0; j--)
        {
            if(array[j]<array[j-1])
            {
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "enter the number of elements that you want in your array: ";
    cin >> n;

    int array[100];

    cout << "enter elements:-" << endl;
    for(int i = 0; i<n; i++) cin >> array[i];

    cout << "sorting array..." << endl;

    insertionsort(array, n);

    cout << "printing array...";
    for(int i = 0; i<n; i++) cout << array[i] << ", ";
}