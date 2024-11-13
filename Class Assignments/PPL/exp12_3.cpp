#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    void getPersonData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }

    void displayPersonData() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee : public Person {
private:
    int employee_id;
    float salary;
public:
    void getEmployeeData() {
        getPersonData();
        cout << "Enter employee ID: ";
        cin >> employee_id;
        cout << "Enter salary: ";
        cin >> salary;
    }

    void displayEmployeeData() const {
        displayPersonData();
        cout << "Employee ID: " << employee_id << endl;
        cout << "Salary: $" << salary << endl;
    }
};

class Student : public Person {
private:
    int student_id;
    string course;
public:
    void getStudentData() {
        getPersonData();
        cout << "Enter student ID: ";
        cin >> student_id;
        cout << "Enter course: ";
        cin >> course;
    }

    void displayStudentData() const {
        displayPersonData();
        cout << "Student ID: " << student_id << endl;
        cout << "Course: " << course << endl;
    }
};

int main() {
    Employee emp;
    Student stud;

    cout << "Enter Employee Details:\n";
    emp.getEmployeeData();

    cout << "\nEnter Student Details:\n";
    stud.getStudentData();

    cout << "\nEmployee Details:\n";
    emp.displayEmployeeData();

    cout << "\nStudent Details:\n";
    stud.displayStudentData();

    return 0;
}
