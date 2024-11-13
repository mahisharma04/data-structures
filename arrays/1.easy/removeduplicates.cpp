#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{

    int array[10] = {1,1,1,2,2,2,3,3,4,5};
    //task is to remove the duplicates from the sorted array.

    //modify the existing array by placing the unique elements from the starting and return the count of the unique elements.


    //below is the OG solution.
    // int first = 0;
    // int temp = 0;
    // for( int i = 1; i<10; i++)
    // {
    //     if(array[i]  == array[first]) temp = i;
    //     else
    //     {
    //         temp++;
    //         first++;
    //         swap(array[temp] , array[first]);
    //     }

    // }

    // cout << "the number of unique elements in the array are: " << first+1;

    //solution after learning 
    int first = 0;
    for(int i = 1; i<10; i++)
    {
        if(array[i] != array[first])
        {
            array[first+1] = array[i];
            first++;
        }
    }

    cout << "unique elements are : " << first+1;

    return 0;
}