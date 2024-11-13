#include <iostream>
using namespace std;


struct Complex {
    float real;
    float imag;
};


Complex addComplexNum(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

int main() {
    Complex num1, num2, sum;


    cout << "Enter the real and imaginary parts of the first complex number: ";
    cin >> num1.real >> num1.imag;


    cout << "Enter the real and imaginary parts of the second complex number: ";
    cin >> num2.real >> num2.imag;

    sum = addComplexNum(num1, num2);


    cout << "Sum = " << sum.real << " + " << sum.imag << "i" << endl;

    return 0;
}
