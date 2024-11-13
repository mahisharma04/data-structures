#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
using namespace std;


int main()
{
    int n;
    cout << "enter the number of elements that you want in your array: ";
    cin >> n;
    int array[n];

    for(int i = 0; i < n; i++) cin >> array[i];

    //hashing
    map<int,int> mpp;
    for (int i = 0; i<n; i++)
    {
        mpp[array[i]]++;
    }

    int q;
    cout << "enter number of queries: ";
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;
        cout << "number of times element appears: " << mpp[number] << endl; //fetching
    }

    //finding the number that is most frequent:
    int maxfreq = 0;
    int maxelement = 0;
    for(auto it : mpp)
    {
        if(it.second > maxfreq)
        {
            maxfreq = it.second;
            maxelement = it.first;
        }
    }

    cout << "the most frequent element is: " << maxelement;

    return 0;
}