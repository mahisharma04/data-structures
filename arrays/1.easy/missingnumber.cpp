#include <iostream>
using namespace std;

int main()
{

    int array[5] = {1,2,4,3}; //here N = 5

    //task is to find the missing number

    //brute force is linear search every number from 1 to 5 with each element in the array TC --> O(N^2) worst case
    //better approach would be to use hashing 
    //2 optimal ways are there 1) using formula of sum of n natural numbers. 2) XOR method

    //sum -> first calculate sum of N natural numbers. if N = 5, Sn = (5 * (5+1)) / 2 = 15 then subtract the sum of all existing elements in the array. missing number = Sn - Sum(array) --> 15- 11 = 4

    //XOR Method: xor of all elements from 1 to N (XOR) xor of all elements in the array, this will give us the missing number

    int xor1 = 0;
    int xor2 = 0;

    for(int i = 0; i<(5-1); i++) //N - 1 becaues we have to calculate xor of 4 elements atmost
    {
        xor2 = xor2 ^ array[i]; //xor of array elements
        xor1 = xor1 ^ (i+1);
    }
    xor1 = xor1 ^ 5; // this finishes xor of all natural elements till N.

    int result = xor1 ^ xor2;

    cout << "missing number is: " << result;



    return 0;
}