#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{

    int array[7] = {1,2,3,4,5,6,7};

    //task is to left rotate by K places, eg. K = 3 --> {4,5,6,7,1,2,3}

    int k;
    cout << "enter the value of K: ";
    cin >> k;

    //brute

    // will be done in 4 steps,(1) reducing K to less than the size of array , for example 15 rotations is just 7+7+1, array is same after rotating 7 times so only noticible change would be that 1 rotation so k = k % size.
    //(2) storing the elements to be shifted into a temp array.
    //(3) shifting the array to k places
    //(4) filling up the temp to the end of the array.

    k = k % 7;
    // int j = 0;

    // int temp[6];
    // for(int i = 0; i<k; i++)
    // {
    //     temp[i] = array[i];
    // }

    // for(int i = k; i<7; i++)
    // {
    //     array[i-k] = array[i];
    // }

    // for(int i = 7-k; i<7; i++)
    // {
    //     array[i] = temp[j];
    //     j++;
    // }

    // //printing the array
    // for(int i = 0; i<7; i++) cout << array[i] << ", ";

    //there is some extra space complexity in this as it uses a temp array we can do it without any extra space too
//------------------------------------------------------------------------------------------------------------------------
    //optimal solution:
    
    //this solution requires some observation 

    /*
    
    you have this array {1,2,3,4,5,6,7} and k is = 3 so it should look like {4,5,6,7,1,2,3}

    the split is after 3. 
    so if you take {1,2,3} and {4,5,6,7} (just observation)
    and reverse them --> {3,2,1,7,6,5,4} and start placing them from the back 
    {4,5,6,7,1,2,3} 
    you get this answer!!

    */

   reverse(array, array+k);
   reverse(array+k, array+7);
   reverse(array,array+7);

    for(int i = 0; i<7; i++) cout << array[i] << ", ";

    //the time complexity is slightly increased but the space complexity is O(1) as modifications are done in the same array.


    return 0;
}