#include <iostream>
using namespace std;

void bubblesort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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

    bubblesort(arr,n);

    for(int i = 0 ; i < n ; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}