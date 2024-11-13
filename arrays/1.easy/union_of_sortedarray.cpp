#include <iostream>
#include <vector>
using namespace std;
int main ()
{

    //task is to create A U B from A and B arrays.
    /*
        for example lets take array A = {1,1,2,3,4,5,5,6}; B = {1,2,11,12};
        A U B = {1,2,3,4,5,6,11,12}
    */

   //brute force (skipped, i didnt do it, but) it is to use set, as it contains unique and ordered elements so just insert every element of a and b in a set and then transfer the elements of that set to an array.

   vector<int> a = {1,1,2,3,4,5,5,6,6,6};
   vector<int> b = {1,2,11,12};
   vector<int> uni;

   int n1 = a.size(); int n2 = b.size();
   // two pointer approach (optimal approach)
   int i = 0 ; 
   int j = 0 ; 
   
   while (i < n1 && j < n2) // while there are still elements in both the arrays.
   {
        if(a[i] <= b[j]) //compares the element of both the array
        {
            if(uni.size() == 0 || uni.back() != a[i]) //checks if the latest element of the union array is not the same as the element we are about to put in. also if it is the first element then we will just go ahead and put in the element.
            {
                uni.push_back(a[i]);    
            }
            i++;
        }
        else
        {
            if(uni.size() == 0 || uni.back() != b[j])
            {
                uni.push_back(b[j]);
            }
            j++;
        }
   }
    //cases for, if one of the arrays gets exhausted first: 
   while(j<n2)
   {
        if(uni.size() == 0 || uni.back() != b[j])
        {
            uni.push_back(b[j]);
        }
        j++;
   }
   while(i<n1)
   {
        if(uni.size() == 0 || uni.back() != a[i])
        {
            uni.push_back(a[i]);
                
        }
        i++;
   }

   //printing union array
   for(int it : uni) cout << it << ", ";

    return 0;
}