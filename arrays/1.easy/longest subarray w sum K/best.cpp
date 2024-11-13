#include <iostream>
#include <vector>
using namespace std;

int longestSubarrayWithSumK(vector<int> nums, int k)
{
    //if the array has only zeros and positives then this one is the BEST approach.
    //using a two pointer approach.

    //keep finding the running sum whenever it exceeds k, shrink it from the left
    int left = 0;
    int sum = 0;
    int n = nums.size();
    int maxLen = 0;

    for(int right = 0; right < n; right++)
    {
        sum += nums[right];

        while(sum > k && left <= right)
        {
            sum -= nums[left];
            left++;
        }
        if(sum == k)
        {
            maxLen = max(maxLen , right - left + 1);
        }
    }
    return maxLen;
}

int main()
{
    vector<int> arr = {2,0,0,3};
    int k;
    cout << "enter K: ";
    cin >> k;

    int result = longestSubarrayWithSumK(arr, k);
    cout << result;
    return 0;
}