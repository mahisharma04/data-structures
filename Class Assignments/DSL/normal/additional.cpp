//use characters for linear search and binary search for binary
//switch case 
//binary search - convert the while to for loop
// linear search - convert the for loop to while loop

//find the time complexity for recursive one and interative one for both the algos

//solution
//converting linear search for loop to while loop
#include <iostream>
#include <vector>

using namespace std;

int linearsearch(vector<int> &vec , int n , int target)
{
    int i = 0;
    while (i < n)
    {
        if(vec[i] == target) return i;
        i++;
    }
    return -1;

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