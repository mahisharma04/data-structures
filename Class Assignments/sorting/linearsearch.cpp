#include <iostream>
using namespace std;

void LinearSearch(int array[], int n, int target)
{
    int indices[100]; // array of multiple indices to handle multiple target occurrence
    int j = 0;
    for(int i = 0; i < n ; i++)
    {
        if(array[i] == target)
        {
            indices[j] = i;
            j++;
        }
    }

    if ( j == 0) cout << "element not found!";
    else
    {
        cout << "printing inxed/indices where target is present.\n";
        for(int i = 0 ; i<j; i++)
        {
            cout << indices[i] << ", ";
        }
    }

}

int main ()
{
    int arr[100];
    int n;

    cout << "Enter the number of elements that you want in your array: ";
    cin >> n;

    cout << "Enter elements:-\n";
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target element that you want to find: ";
    cin >> target;

    cout << "searching..." << endl;

    LinearSearch(arr,n,target);

    

    return 0;
}