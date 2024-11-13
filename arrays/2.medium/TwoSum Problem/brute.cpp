#include <iostream>
#include <vector>
using namespace std;

//task 1: to return true if two sum exists and false if it doesnt
//tast 2: to return the index of both the numbers that sum up to be the two sum number

bool twosumexists(vector<int> arr, int k)
{
    for(int i = 0; i<arr.size(); i++)
    {
        for(int j = i+1; j<arr.size(); j++)
        {
            if( (arr[i] + arr[j]) == k) return true;
        }
    }
    return false;
}

pair<int,int> twoSumIndices(vector<int> arr, int k)
{
    for(int i = 0; i<arr.size(); i++)
    {
        for(int j = i+1; j<arr.size(); j++)
        {
            if( (arr[i]+arr[j]) == k )
            {
                return make_pair(i,j);
            }
        }
    }
    return make_pair(-1,-1);
}

int main ()
{

    vector<int> arr = {2,6,5,8,11};
    int k;
    cout << "enter k: ";
    cin >> k;

    // if(twosumexists(arr,k)) cout << "yes.";
    // else cout << "no.";

    pair<int,int> result = twoSumIndices(arr,k);
    cout << result.first << " " << result.second;

    return 0;
}