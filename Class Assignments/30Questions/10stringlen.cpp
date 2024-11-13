#include <iostream>
#include <string>
using namespace std;

int main ()
{

    string str;
    cout << "enter your string: ";
    getline(cin, str);
    int count = 0;

    // for(auto it = str.begin(); it != str.end(); it++)
    // {
    //     count++;
    // }

    //another way:

    for (char ch : str) //ranged based loop
    {
        count++;
    }

    cout << "length is: " << count;

    return 0;
}