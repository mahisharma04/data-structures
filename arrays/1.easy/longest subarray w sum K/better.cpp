#include <iostream>
#include<vector>
#include<map>
using namespace std;

//this is the best solution if the array includes zeros, positives as well as negatives. 
//you cannot optimize it further.

//Time complexity -> O(N x LogN) if using ordered map
//Space complexity -> O(N) because of storing prefix sums in map.
//Time complexity -> O(N) is using unordered map and there are no collisions, worst case if collisions happen O(N^2).


int longestSubarrayWithSumK(vector<int> arr, int k)
{
    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for(int i = 0; i<arr.size(); i++)
    {
        sum += arr[i];
        if(sum == k)
        {
            maxLen = max(maxLen, i+1);
        }
        int rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end())
        {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        preSumMap[sum] = i;
    }
    return maxLen;
}

int main()
{
    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};
    cout << "Enter K: ";
    int k;
    cin >> k;

    int result = longestSubarrayWithSumK(arr,k);
    cout << result;
}