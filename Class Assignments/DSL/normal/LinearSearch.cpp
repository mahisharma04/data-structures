#include <iostream>
#include <vector>

using namespace std;

int linearsearch(vector<int> &vec , int n , int target)
{
    for(int i = 0; i<n; i++)
    {
        if(vec[i] == target) return i;
    }
    return -1;

    //while loop approach

    // int i = 0;
    // while (i < n)
    // {
    //     if(vec[i] == target) return i;
    //     i++;
    // }
    // return -1;
}

int main ()
{

    int n;
    cout << "enter the number of elements that you want in your array: ";
    cin >> n;

    vector<int> vec(n);

    cout << "enter elements into the array:-\n";
    for(int i = 0; i<n; i++)
    {
        cin >> vec[i];
    }

    int target;
    cout << "enter the target that you want to find: ";
    cin >> target;

    int result = linearsearch(vec,n,target);

    if(result == -1)
    {
        cout << "element not found";
    }
    else
    {
        cout << "element found at index: " << result;
    }




    return 0;
}