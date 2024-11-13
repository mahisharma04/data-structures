#include <iostream>
using namespace std;

int main ()
{

    int arr[5] = {5,2,7,6,7};
    
    //finding the second largest element in the array

    int largest = arr[0];
    int secondlargest = -1;

    for(int i = 0 ; i < 5 ; i++)
    {
        if(arr[i] > largest)
        {
            int temp = largest;
            largest = arr[i];
            secondlargest = temp;
        }
        if(arr[i] > secondlargest && arr[i] < largest)
        {
            secondlargest = arr[i];
        }
    }
    cout << "The second largest element in the array is: " << secondlargest;



    return 0;
}