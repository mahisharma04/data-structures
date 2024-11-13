#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    Number(int val = 0) : value(val) {}

    Number& operator++() {
        ++value;
        return *this;
    }

    Number operator++(int) {
        Number temp = *this;
        value++;
        return temp;
    }

    Number operator+(const Number& other) {
        return Number(value + other.value);
    }

    bool operator<(const Number& other) {
        return value < other.value;
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    int choice, val1, val2;
    Number num1, num2, result;

    do {
        cout << "\nMenu:\n";
        cout << "1. Prefix Increment\n";
        cout << "2. Postfix Increment\n";
        cout << "3. Add Two Numbers\n";
        cout << "4. Compare Two Numbers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a number: ";
                cin >> val1;
                num1 = Number(val1);
                ++num1;
                cout << "After Prefix Increment: ";
                num1.display();
                break;

            case 2:
                cout << "Enter a number: ";
                cin >> val1;
                num1 = Number(val1);
                num1++;
                cout << "After Postfix Increment: ";
                num1.display();
                break;

            case 3:
                cout << "Enter first number: ";
                cin >> val1;
                cout << "Enter second number: ";
                cin >> val2;
                num1 = Number(val1);
                num2 = Number(val2);
                result = num1 + num2;
                cout << "Result of Addition: ";
                result.display();
                break;

            case 4:
                cout << "Enter first number: ";
                cin >> val1;
                cout << "Enter second number: ";
                cin >> val2;
                num1 = Number(val1);
                num2 = Number(val2);
                if (num1 < num2)
                    cout << "First number is less than the second number.\n";
                else
                    cout << "First number is not less than the second number.\n";
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
