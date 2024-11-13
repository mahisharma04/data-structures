#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> zerotoend(vector<int> &vec, int n)
{
    vector<int> temp;
    int number_zeros=0;
    for(int i = 0; i<n; i++)
    {
        if(vec[i] == 0) number_zeros++;
    }

    int number_nonzeros = n - number_zeros;

    for(int i = 0 ; i<n; i++)
    {
        if(vec[i] != 0)
        {
            temp.push_back(vec[i]);
        }
    }

    for(int i = number_nonzeros; i<n; i++)
    {
        temp.push_back(0);
    }

    return temp;


}

int main()
{

    int n;
    cout << "enter n: ";
    cin >> n;

    vector<int> vec(n);

    cout << "enter elements in your array:- " << endl;
    for(int i = 0 ; i < n; i++)
    {
        cin >> vec[i];
    }
    
    //task is to shift all zeros to the end of the array for eg.
    //{1,0,2,2,0,5,2,0} --> {1,2,2,5,2,0,0,0}

    //brute force

    /*
    
    i know that there are n elements in the array.
    i can go through the array and find the number of non zero elements lets say (x) and rest will be number of zero elements (y)
    i can create a temp array and add all the non zero elements in the array.
    then i can push back y number of zeros in the temp array

    hence solved


    */

//    vector<int> result = zerotoend(vec,n);

//    for(auto it : result)
//    {
//         cout << it << ", ";
//    }

   //optimal solution has space complexity of O(1) Time complexity still remains almost the same that is O(N).

    //1) we will use two pointers, a pointer j at first zero of the array and a pointer i which will search for non zero element in the array and swap j and i, as well as increment j++ after the swap as the zero will be swapped and we need to move to the zero again.

    //below is the code for setting j to the first zero in the array
    int j = -1;
    for(int i = 0; i<n; i++)
    {
        if(vec[i] == 0)
        {
            j = i;
            break;
        }
    }

    //this is for swapping, (i = j+1 because we are gonna be searching for a non zero element after the first zero obviously.)
    for(int i = j+1; i<n; i++)
    {
        if(vec[i] != 0)
        {
            swap(vec[j], vec[i]);
            j++;
        }
    }

    for(int it : vec) cout << it << ", "; //printing the array

    return 0;
}