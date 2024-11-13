#include <iostream>
using namespace std;

class imaginary {
private:
    int real;
    int imag;

public:
    imaginary() : real(0), imag(0) {}
    imaginary(int real1, int imag1) : real(real1), imag(imag1) {}

    friend imaginary add(imaginary& obj1, imaginary& obj2);

    void display() {
        cout << real << " + " << imag << "i" << endl;
        cout << "Real Part = " << real << ", Imaginary Part = " << imag << "i" << endl;
    }
};

imaginary add(imaginary& obj1, imaginary& obj2) {
    return imaginary(obj1.real + obj2.real, obj1.imag + obj2.imag);
}

int main() {
    imaginary obj1(50, 20);
    imaginary obj2(5, 10);

    cout << "First Complex Number: ";
    obj1.display();
    cout << "Second Complex Number: ";
    obj2.display();

    imaginary result = add(obj1, obj2);
    cout << "Sum of Complex Numbers: ";
    result.display();

    return 0;
}
