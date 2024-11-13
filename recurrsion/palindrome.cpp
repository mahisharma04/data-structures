#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

bool palindrome(int i, string &str)
{
    if(i>=str.size()/2) return true;
    if(str[i] != str[str.size() - i - 1]) return false;
    palindrome(i+1, str); 
}

int main()
{

    string s;
    cout << "enter your string: ";
    getline(cin,s);
    if(palindrome(0,s)) cout << "The string is a palindrome.";
    else cout << "The string is not palindrome.";

    return 0;
}