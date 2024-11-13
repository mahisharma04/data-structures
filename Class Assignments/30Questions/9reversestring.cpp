#include <iostream>
using namespace std;

void revstring(const string &str)
{
    string reversedstring = str;
    int size = reversedstring.size();
    for(int i = 0; i<=size/2 ; i++)
    {
        swap(reversedstring[i], reversedstring[size-i-1]);
    }
    // cout << "reversed string is : "<< reversedstring << endl;
}

int main ()
{

    string str;
    cout << "enter your string: ";
    getline(cin , str);

    revstring(str);

    cout << "reversed string: " << str;


    return 0;
}