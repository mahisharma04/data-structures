#include <iostream>
#include <vector>
#include <string>
using namespace std;

void marksheet(string name, int prn, vector<float> arr)
{
    int total = 0;
    int size = arr.size();
    for(int i = 0; i < size; i++)
    {
        total = total + arr[i];
    }
    float percentage = total/size;

    int prn;

    cout << name << " has scored a total of " << percentage << "%." << endl;
}

int main ()
{
    string name;
    cout << "enter name of the student: ";
    getline(cin, name);

    vector<float> marks(5);
    for(int i = 0; i < 5; i++)
    {
        cout << "enter marks of subject " << i+1 << ": " ;
        cin >> marks[i];
    }

    marksheet(name,marks);
    
    return 0;
}