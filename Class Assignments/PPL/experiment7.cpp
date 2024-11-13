#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int totalMarks;
    int maxMarks;
    int numberOfSubjects;
    int marks[10];

public:
    Student(string studentName, int numSubjects, int maxMarksPerSubject)
        : name(studentName), numberOfSubjects(numSubjects), maxMarks(maxMarksPerSubject), totalMarks(0) {}

    void inputMarks() {
        for (int i = 0; i < numberOfSubjects; ++i) {
            cout << "Please enter the marks for subject " << (i + 1) << ": ";
            cin >> marks[i];

            while (marks[i] < 0 || marks[i] > maxMarks) {
                cout << "Invalid marks. Please enter marks between 0 and " << maxMarks << ": ";
                cin >> marks[i];
            }
            totalMarks += marks[i];
        }
    }

    double calculatePercentage() {
        return (static_cast<double>(totalMarks) / (numberOfSubjects * maxMarks)) * 100;
    }

    void display() {
        cout << "\n----- Marksheet -----\n";
        cout << "Student Name: " << name << endl;
        cout << "---------------------\n";
        cout << left << setw(15) << "Subject" << setw(15) << "Marks Obtained" << endl;
        cout << "---------------------\n";

        for (int i = 0; i < numberOfSubjects; ++i) {
            cout << left << setw(15) << ("Subject " + to_string(i + 1)) << marks[i] << endl;
        }

        cout << "---------------------\n";
        cout << "Total Marks Obtained: " << totalMarks << " out of " << numberOfSubjects*maxMarks << endl;
        cout << fixed << setprecision(2) << "Percentage: " << calculatePercentage() << "%" << endl;
        cout << "---------------------\n";
    }
};

int main() {
    string studentName;
    int numSubjects, maxMarksPerSubject;

    cout << "Welcome! Please enter the student's name: ";
    getline(cin, studentName);
    cout << "How many subjects does the student have (max 10)? ";
    cin >> numSubjects;
    cout << "What is the maximum marks for each subject? ";
    cin >> maxMarksPerSubject;

    Student student(studentName, numSubjects, maxMarksPerSubject);
    student.inputMarks();
    student.display();

    return 0;
}
