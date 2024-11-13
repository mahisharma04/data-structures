#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
//finding frequency of an element in a given array.

int main()
{

    string str;
    cout << "enter your string : ";
    cin >> str;
    
    //pre computation
    int hash[256] = {0};
    for(int i =0; i<str.size(); i++)
    {
        hash[str[i]]++;
    }

    char c;
    cout << "how many times character appears: ";
    cin >> c;
    cout << hash[c];


    return 0;
}