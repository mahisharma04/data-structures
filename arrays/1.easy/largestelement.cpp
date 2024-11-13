#include <iostream>
using namespace std;

int main ()
{
    int arr[5] = {5,19,3,7,3};

    //finding the largest element in the array

    int max = 0;
    for(int i = 0; i < 5; i++)
    {
        if(arr[i] > max) max = arr[i];
    }

    cout << "largest element of the array is : " << max;
} 