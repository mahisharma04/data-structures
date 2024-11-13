#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string str = "alpha";
    int count = 0;
    for(char ch : str)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' )
        {
            count++;

        } //you can also include capital letters for vowels.
    }
    cout << "number of vowels in this string are: " << count;
}