#include <iostream>
#include <string>
using namespace std;

class student{
    private:
    string Name;
    int TotalMarks;
    int NumSubjects;
    int MaxMarksPerSubject;
    int marks[50];

    public:
    student(string name, int numSubject, int maxMarksPerSubject) : Name(name), NumSubjects(numSubject), MaxMarksPerSubject(maxMarksPerSubject), TotalMarks(0) {}

    void addMarks(){
        for(int i = 0; i<NumSubjects; i++){
            cout << "Enter marks of Student in Subject #" << i+1 << " : ";
            cin >> marks[i];

            while(marks[i] < 0 || marks[i] > MaxMarksPerSubject){
                cout << "Invalid marks input. Please Re-try.";
                cin >> marks[i];
            }

            TotalMarks += marks[i];
        }
    }

    void displayResult(){
        cout << endl;
        cout << "---------x------------" << endl;
        cout << "Student Result:" << endl;
        cout << "Name of the Student: " << Name << endl;
        cout << "Number of Courses: "<< NumSubjects << endl;
        cout << "Total Marks Scored by Student: " << TotalMarks <<"/" << NumSubjects*MaxMarksPerSubject << endl;
        cout << "Percentage % : " << (static_cast<float>(TotalMarks)/(NumSubjects*MaxMarksPerSubject)) * 100 << endl;
        cout << "--------x-------------" << endl;
    }

};

int main ()
{

    student Mahi = student("Mahi Sharma", 3, 100);
    Mahi.addMarks();

    Mahi.displayResult();

    return 0;
}