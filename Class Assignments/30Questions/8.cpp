#include <cmath>
#include <iostream>
using namespace std;
//find largest of the three numbers

int largestnum(int array[])
{
    int highest = 0;
    for (int i = 0; i<3; i++)
    {
        if(array[i] > highest) highest = array[i];
    }
    return highest;
}

int main()
{

    int array[3];
    cout << "enter elements into array: ";
    cin >> array[0] >> array[1] >> array[2];

    
    int index = largestnum(array); 

    cout << "largest element is: "<< index;

    return 0;
}