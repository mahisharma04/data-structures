#include <iostream>
using namespace std;

class Complex{
    int real;
    int imag;

    public:
    Complex() : real(0), imag(0) {}
    Complex(int r, int i) : real(r), imag(i) {}

    void display(){
        cout << real << " + " << imag << "i" << endl;
    }

    Complex operator+(Complex member){
        Complex temp;
        temp.real = real + member.real;
        temp.imag = imag + member.imag;
        return temp;
    }

};

int main ()
{

    Complex c1 = Complex(5, 10);
    Complex c2 = Complex(100, 100);

    Complex c3;
    c3 = c1+c2;

    c3.display();
    

    return 0;
}