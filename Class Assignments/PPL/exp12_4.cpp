#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int prn;
public:
    void getStudentData() {
        cout << "Enter student's name: ";
        cin >> name;
        cout << "Enter PRN: ";
        cin >> prn;
    }

    void displayStudentData() const {
        cout << "Name: " << name << endl;
        cout << "PRN: " << prn << endl;
    }
};

class UT_Marks : virtual public Student {
protected:
    float ut_marks;
public:
    void getUTMarks() {
        cout << "Enter Unit Test Marks: ";
        cin >> ut_marks;
    }

    void displayUTMarks() const {
        cout << "Unit Test Marks: " << ut_marks << endl;
    }
};

class Sports : virtual public Student {
protected:
    float sports_score;
public:
    void getSportsScore() {
        cout << "Enter Sports Score: ";
        cin >> sports_score;
    }

    void displaySportsScore() const {
        cout << "Sports Score: " << sports_score << endl;
    }
};

class Result : public UT_Marks, public Sports {
    float total_score;
public:
    void calculateTotal() {
        total_score = ut_marks + sports_score;
    }

    void displayResult() {
        displayStudentData();
        displayUTMarks();
        displaySportsScore();
        cout << "Total Score: " << total_score << endl;
    }
};

int main() {
    Result studentResult;

    cout << "Enter Student Details:\n";
    studentResult.getStudentData();
    studentResult.getUTMarks();
    studentResult.getSportsScore();
    
    studentResult.calculateTotal();

    cout << "\nStudent Result:\n";
    studentResult.displayResult();

    return 0;
}
