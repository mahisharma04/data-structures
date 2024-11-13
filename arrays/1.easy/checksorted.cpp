#include <iostream>
using namespace std;

int main ()
{
    int arr[5] = {1,2,3,3 ,4};

    //to check if the array is sorted
    int sorted = 1;
    for(int i = 0 ; i < 4; i++)
    {
        if(arr[i] > arr[i+1])
        
        {
            sorted = 0;
            break;
        }
    }
    if(sorted) cout << "The array is sorted.";
    else cout << "The array is not sorted.";
}