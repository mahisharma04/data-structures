#include <iostream>
using namespace std;

void quicksort(int list[], int low, int high)
{
    int pivot, i , j, temp;
    if(low < high)
    {
        pivot = low; //first + rand() % (last - first + 1)
        i = low;
        j = high;
        while( i < j)
        {
            while(list[i] <= list[pivot] && i <= high)
            {
                i++;
            }
            while ( list[j] > list[pivot] && j > low)
            {
                j--;
            }
            if(i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }

            temp = list[j];
            list[j] = list[pivot];
            list[pivot] = temp;
            quicksort(list, 0 , j-1);
            quicksort(list, j+1, high);
        }
    }
}

int main ()
{

    int list[50];
    int size, i;

    cout << "Enter the number of elements: ";
    cin >> size;
    cout << "Enter the elements in your array: ";
    for( int i = 0; i<size; i++) cin >> list[i];

    cout << "sorting array...\n";
    quicksort(list,0,size-1);

    cout << "printing sorted array: " << endl;
    for(int i = 0 ; i < size; i++) cout << list[i] << ", ";



    return 0;
}