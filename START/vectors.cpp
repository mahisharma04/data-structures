#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
    vector<int> v;
    v = {2,4,6,8,10};
    
    //iterator is like pointer
    


    // for ( auto it : v)
    //     cout << it << ' ';
    cout << "original vector : ";
    for(auto it = v.begin(); it != v.end(); it++) // similar to null terminator and string case in c 
        cout << *(it) << ' ';

    cout << endl;

    //------------------------------------------

    //to add an element at the back of the vector there are two things that you can use : 
    // push_back() and emplace_back()

    //inserting and deleting elements:
    //v.insert(position to insert at , element to be inserted)
    cout << "vector after inserting element: ";
    v.insert(v.begin()+2,5);

    for(auto it : v)
        cout << it << ' ';

    //v.erase(start,end) start is inclusive and end is exclusive
    cout << endl;

    v.erase(v.begin()+1, v.begin()+5);

    cout<<"vector after deletion: ";

    for(auto it : v)
        cout << it << ' ';

    cout << endl;
    //to clear a vector we have
    //v.clear();
    // to check if vector is empty or not we have
    //v.empty()

    cout << v.empty(); //gives a boolean value 0 for false and 1 for true
}