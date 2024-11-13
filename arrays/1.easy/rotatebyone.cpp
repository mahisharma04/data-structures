#include <iostream>
using namespace std;

int main ()
{

    int array[5] = {1,4,6,2,5};

    //task is to rotate one place from left --> {4,6,2,5,1}

    int temp = array[0];
    for(int i = 1 ; i < 5; i++)
    {
        array[i-1] = array[i];
    }
    array[4] = temp;

    //printing array

    for(int i = 0; i<5; i++)
    {
        cout << array[i] << ", ";
    }

    //TC ~ O(N)

    return 0;
}