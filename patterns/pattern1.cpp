#include <iostream>
using namespace std;

void pattern1(int n)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<=i; j++)
        {
            cout << '*';
        }
        cout << endl;
    }
}
void pattern2(int n)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0 ; j<=i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern3(int n)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0 ; j<=i; j++)
        {
            cout << j+1 << ' ';
        }
        cout << endl;
    }
}
void pattern4(int n)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0 ; j<=i; j++)
        {
            cout << i+1 << ' ';
        }
        cout << endl;
    }
}
void pattern5(int n)
{
    for(int i = 0 ; i<n; i++)
    {
        for(int j = n-i; j>0; j--)
        {
            cout << "* ";
        }
        cout << endl;

    }
}
void pattern6(int n)
{
    for(int i = 0 ; i<n; i++)
    {
        for(int j = n-i; j>0; j--)
        {
            cout << n-j+1-i << ' ';
        }
        cout << endl;

    }
}
void pattern7(int n)

{
    //for loop for spaces, second for loop for starts, third for loop for spaces.
    for(int i = 0 ; i<n; i++)
    {
        for(int j = 0 ; j<n-i-1; j++)
        {
            cout << ' ';
        }
        for(int j = 0; j<2*i + 1; j++)
        {
            cout << '*';
        }
        for(int j = 0 ; j<n-i-1; j++)
        {
            cout << ' ';
        }

        cout << endl;
    }

}
void pattern8(int n)



{
    for(int i = 0 ; i<n; i++)
    {
        for(int j = 0 ; j<i; j++)
        {
            cout << ' ';
        }
        for(int j = 0; j<2*n-1-2*i; j++)
        {
            cout << '*';
        }
        for(int j = 0 ; j<i; j++)
        {
            cout << ' ';
        }
        cout << endl;
    }
}
void pattern10(int n)
{
    for(int i = 0; i<2*n - 1; i++)
    {
        int stars = i;
        if(i >= n)
        {
            stars = 2*n - i - 2;
        }
        for(int j = 0; j<=stars; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void pattern11(int n)
{
    int start = 1;
    for(int i = 0; i<n; i++)
    {
        if(i % 2 == 0)
        {
            start = 1;
        }
        else
        {
            start = 0;
        }
        for(int j = 0; j<=i; j++)
        {
            cout << start << ' ';
            start = 1 - start;
        }
        cout << endl;
    }
}
void pattern12(int n)
{
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=i; j++)
        {
            cout << j << ' ';
        }
        for(int j = 1; j<2*n - 2*i; j++)
        {
            cout << "   ";
        }
        for(int j = i; j>=1; j--)
        {
            cout << j<< ' ';
            
        }
        cout << endl;
    }
}
void pattern13(int n)
{
    int start = 1;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=i; j++)
        {
            cout << start << ' ';
            start++;
        }
        cout << endl;
    }
}
void pattern14(int n)
{
    int alphabet = 64;
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=i; j++)
        {
            cout << char(alphabet + j) << ' ';
        }
        cout << endl;
    }
}
void pattern15(int n)
{
    for(int i = 0; i<n; i++)
    {
        int alphabet = 65;
        for(int j = i; j<n; j++)
        {
            cout << char(alphabet) << ' ';
            alphabet++;
        }
        cout << endl;
    }
}
void pattern16(int n)
{   
    
    int alphabet = 65;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<=i; j++)
        {
            cout << char(alphabet) << ' ';
        }
        alphabet += 1;
        cout << endl;
    }
}
void pattern17(int n)
{
    
    for(int i = 0; i<n; i++)
    {
            char ch = 'A';
        for(int j = 0; j<n-1-i; j++)
        {
            cout << ' ';
        }
        // for(int j = 0; j<2*i + 1; j++)
        // {
        //     int len = 2*i+1;
            
        //     if(j < len/2)
        //     {
        //         cout << (ch) << ' ';
        //         ch++;
        //     }
        //     else
        //     {
        //         cout << ch-- << ' ';
        //     }
        // }
        // 2nd method
        int breakpoint = (2*i + 1) / 2;
        for(int j = 1; j<= 2*i + 1; j++)
        {
            cout << ch << ' ';
            if (j<=breakpoint)
                ch++;
            else
                ch--;
        }
        for(int j = 0; j<n-1-i; j++)
        {
            cout << ' ';
        }
        
        cout << endl;
    }
}
void pattern18(int n)
{
    for(int i = 0; i < n; i++)
    {
        char ch = char(n+64);
        for(int j = 0; j<=i; j++)
        {
            cout << ch << ' ';
            ch--;
        }
        cout << endl;
    }
}
void pattern19_1(int n)
{
    for(int i = 0; i<n; i++)
    {
        //for characters
        for(int j = 0; j< n - i; j++)
        {
            cout << '*';
        }
        //for spaces
        for(int j = 0; j<2*i; j++)
        {
            cout << ' ';
        }
        for(int j = 0; j< n - i; j++)
        {
            cout << '*';
        }
        cout << endl;

    }
}
void pattern19_2(int n)
{
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<=i; j++)
        {
            cout << '*';
        }
        for(int j = 0; j<2*n - 2*i - 2; j++)
        {
            cout << ' ';
        }
        for(int j = 0; j<= i; j++)
        {
            cout << '*';
        }
        cout << endl;
    }
}
void pattern20_1(int n)
{
    int initialSpaces = 2*n - 2;
    for(int i = 0; i<n; i++)
    {
        //for characters
        for(int j = 0; j<= i; j++)
        {
            cout << '*' << ' ';
        }
        //for spaces
        for(int j = 0; j<initialSpaces; j++)
        {
            cout << ' ';
        }
        initialSpaces -= 2;
        for(int j = 0; j<= i; j++)
        {
            cout << '*' << ' ';
        }
        cout << endl;

    }
}
void pattern20_2(int n)
{
    for(int i = 0; i<n-1; i++)
    {
        //for characters
        for(int j = 0; j<n-1-i; j++)
        {
            cout << '*' << ' ';
        }
        //for spaces
        for(int j = 0; j<2*i + 2; j++)
        {
            cout << ' ';
        }
        for(int j = 0; j<n-1-i; j++)
        {
            cout << '*' << ' ';
        }
        cout << endl;

    }
}
void pattern21(int n) //i liked it
{
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(i == 0 || j == 0 || i == n-1 || j == n-1)
                cout << '*';
            else
                cout << ' ';
        }
        cout << endl;
    }
}


void pattern22(int n) // little tough (pending) 
{
    
}


int main()

{
    int n;
    cout << "enter number of rows you want of the pattern: ";
    cin >> n;
    cout << endl;
    
    pattern22(n);
    



    return 0;
}