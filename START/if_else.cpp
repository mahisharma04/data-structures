#include<iostream>
using namespace std;

int main()
{

    float marks;
    cout << "enter the marks obtained by the student: ";
    cin >> marks;
    if(marks >= 80)
    {
        cout << "Student has gotten A grade!";
    }
    else if(marks >= 60 && marks < 80)
    {
        cout << "Student has gotten B grade!";
    }
    else if(marks >= 40 && marks < 60)
    {
        cout << "Student has gotten C grade!";
    }
    else if ( marks >= 20 && marks < 40)
    {
        cout << "Student has gotten D grade!";
    }
    else if(marks < 20)
    {
        cout << "Student has falled..";
    }

    return 0;
}