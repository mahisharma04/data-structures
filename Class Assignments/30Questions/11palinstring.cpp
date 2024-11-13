#include <iostream>
#include <string>
using namespace std;
string revstring(const string &str)
{
    string reversedstring = str;
    int size = reversedstring.size();
    for(int i = 0; i<=size/2 ; i++)
    {
        swap(reversedstring[i], reversedstring[size-i-1]);
    }
    return reversedstring;
}

int main ()
{

    string str;
    cout << "enter your string: ";
    getline (cin , str);
    
    string str2 = revstring(str);

    if(str == str2) cout << "palindrome";
    else cout << "not palindrome";


    return 0;
}