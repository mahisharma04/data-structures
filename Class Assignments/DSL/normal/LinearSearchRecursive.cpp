#include <iostream>
#include <vector>

using namespace std;

int linearsearch(vector<int> &vec , int n , int target , int index)
{
    int position = 0;
    if(index >= n) return 0;
    else if(vec[index] == target)
    {
        position = index + 1;
        return position;
    }
    return linearsearch(vec,n,target,index+1);
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

    int result = linearsearch(vec,n,target, 0);

    if(result == 0)
    {
        cout << "element not found";
    }
    else
    {
        cout << "element found at position: " << result;
    }




    return 0;
}