#include <iostream>
#include <vector>
using namespace std;

//insertion sort sorts the array one element at a time. Time complexity is O(n^2) worst and average case. O(n) in best case.

void insertionsort(vector<int> &vec, int n)
{
    int key, i , j;
    for(i = 1; i<n; i++)
    {
        key = vec[i];
        j = i - 1;
        while( j >= 0 && vec[j] > key)
        {
            //if j element is bigger than key, shift it to right.
            vec[j+1] = vec[j];
            j--; //loop condition
        }
        //insert key at the correct position
        vec[j+1] = key;
    }
}

int main()
{

    int n;
    cout << "Enter the number of elements that you want in the array: ";
    cin >> n;
    vector<int> vec(n);

    cout << "Enter elements into the array:- " << endl;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> vec[i];
    }

    cout << "sorted array: " << endl;
    insertionsort(vec, n);

    for (int i = 0; i < n ; i++)
    {
        cout << vec[i] << ", ";
    }


    return 0;
}