#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};

    //task : Task is to find longest subarray with sum k, lets say [k=3]

    vector<int> len;

    int k;
    cout << "enter k: ";
    cin >> k;

    

    for(int i = 0; i<arr.size(); i++)
    {
        int j = i;
        int sum = 0;
        while(j < arr.size())
        {
            sum += arr[j];
            if(sum == k)
            {
                len.push_back(j-i+1);
            }
            if(sum >= k)
            {
                break;
            }
            j++;
        }
        
    }

    //now len array has the lengths of all the subarrays whose sum is equal to k. we need to find the maximum element of this array now.

    if(len.empty())
    {
        cout << "no such subarray found.";
        return 0;
    }

    int maxi = 0;
    for(int i = 1; i<len.size(); i++)
    {
        if(len[i] > len[maxi])
        {
            maxi = i;
        }
    }

    cout << "the longest subarray with sum " << k << " is: " << len[maxi];
     
//Time complexity i near about O(n^2)

    return 0;
}