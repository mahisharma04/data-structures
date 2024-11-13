#include <iostream>
using namespace std;

void selectionsort(int arr[], int n)
{
    for(int i = 0 ; i < n-1; i++)
    {
        int min = i;
        for(int j = i; j<n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main()
{

    int arr[100];
    int n;
    cout << "enter the number of elements that you want in your array: "; cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cout << "Element number " << i+1 << " : ";
        cin >> arr[i];
    }

    cout << "Sorting array...\n";

    selectionsort(arr,n);

    for(int i = 0 ; i < n ; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}