#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &vec, int low, int mid, int high)
{
    vector<int> temp;
    int leftarray = low;
    int rightarray = mid + 1;

    while (leftarray <= mid && rightarray <= high)
    {
        if(vec[leftarray] <= vec[rightarray])
        {
            temp.push_back(vec[leftarray]);
            leftarray++;
        }
        if(vec[rightarray] <= vec[leftarray])
        {
            temp.push_back(vec[rightarray]);
            rightarray++;
        }
    }
    while(leftarray <= mid)
    {
        temp.push_back(vec[leftarray]);
        leftarray++;

    }
    while(rightarray <= high)
    {
        temp.push_back(vec[rightarray]);
        rightarray++;
    }
    for(int i = low; i <= high; i++)
    {
        vec[i] = temp[i-low];
    }
}

void mergesort(vector<int> &vec, int low, int high)
{
    if (low >= high) return; 
    int mid = (low + high) / 2;
    mergesort(vec, low , mid);
    mergesort(vec, mid + 1, high);
    //merge function yet to be made...
    merge(vec, low, mid, high);
}

int main ()
{
    int n;
    cout << "enter the size of your array: ";
    cin >> n;
    vector<int> vec(n);

    //enter elements in vector

    for(int i = 0; i<n; i++) cin >> vec[i];

    cout << "printing array...";
    for (auto it = vec.begin(); it != vec.end(); it++)
        cout << *it << ", ";

    cout << endl << "sorting array...";
    
    mergesort(vec,0,n-1);

    for(int i = 0; i<n; i++)
    {
        cout << vec[i] << ", ";
    }

    return 0;
}