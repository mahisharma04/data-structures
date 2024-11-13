#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    //task is to create A ∩ B from A and B arrays.
    /*
        for example lets take array A = {1,1,2,3,4,5,5,6}; B = {1,2,11,12};
        A ∩ B = {1,2};
    */ 
   // so i will create a new array named intersection. this will be the answer array
   /*
   following a two pointer approach i will be placed on first array's first element, j will be placed on second array's first element
   if i element and j element are equal then put that element into the answer array, and increment both i and j, if not same increment the pointer which contains smaller element.
   */

    vector<int> a = {1,2,2,3,3,4,5,6};
    vector<int> b = {2,3,3,5,6,6,7};
    vector<int> intersection;

    int n1 = a.size(); int n2 = b.size();

    int i = 0; int j = 0;
    while(i < n1 && j < n2)
    {
        if(a[i] != b[j])
        {
            if(a[i] < b[j]) i++;
            if(b[j] < a[i]) j++;
        }
        else
        {
            intersection.push_back(a[i]);
            i++;
            j++;
        }
    }

    for(int it : intersection) cout << it << ", ";



    return 0;
}

