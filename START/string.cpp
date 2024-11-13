#include<iostream>
//string comes under the standard library of cpp that is the std namespace. its not a fundamental datatype.
using namespace std;
int main()
{
    string str;
    cout << "enter your string: ";
    getline(cin,str);
    cout << "the string you entered is: \n" << str;

    return 0;
}