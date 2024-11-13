#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int roll_no;
public:
    void getStudentData() {
        cout << "Enter student's name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> roll_no;
    }

    void displayStudentData() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << roll_no << endl;
    }
};

class Marks : public Student {
protected:
    float marks[3];
public:
    void getMarks() {
        cout << "Enter marks for three subjects: ";
        for (int i = 0; i < 3; ++i) {
            cin >> marks[i];
        }
    }

    void displayMarks() const {
        cout << "Marks: ";
        for (int i = 0; i < 3; ++i) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};

class Result : public Marks {
    float total;
    float average;
public:
    void calculateResult() {
        total = 0;
        for (int i = 0; i < 3; ++i) {
            total += marks[i];
        }
        average = total / 3;
    }

    void displayResult() {
        displayStudentData();
        displayMarks();
        cout << "Total Marks: " << total << endl;
        cout << "Average Marks: " << average << endl;
    }
};

int main() {
    Result studentResult;
    studentResult.getStudentData();
    studentResult.getMarks();
    studentResult.calculateResult();
    studentResult.displayResult();

    return 0;
}
