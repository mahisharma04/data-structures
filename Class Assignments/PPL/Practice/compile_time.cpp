#include <iostream>
using namespace std;

class Shape{
    protected:
    string Name;
    int Sides;

    public:
    Shape(string name, int sides) : Name(name), Sides(sides) {}

    void display(){
        cout << "Name of the shape: " << Name << endl;
        cout << "Number of sides: " << Sides << endl;
    }

};

class Square : public Shape{
    private:
    int SideLength;

    public:
    Square(int sidelength) : Shape("Square", 4) , SideLength(sidelength) {}

    float area(int s){
        return s*s;
    }
};

class Triangle : public Shape{
    private:
    int Base;
    int Height;

    public:
    Triangle(int base, int height) : Shape("Triangle", 3), Base(base), Height(height) {}

    float area(int b, int h){
        return (1/2) * b * h;
    }
};

int main (){

    Square s1;
    cout << "Area of Square: " << s1.area(20) << endl;
    Triangle t1;
    cout << "Area of Triangle: " << t1.area(20) << endl;


}