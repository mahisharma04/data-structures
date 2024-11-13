#include <iostream>
using namespace std;

class Polygon {
protected:
    int width, height;
public:
    virtual int area() = 0;

    void set_values(int w, int h) {
        width = w;
        height = h;
    }
};

class Rectangle : public Polygon {
public:
    int area() override {
        return width * height;
    }
};

class Triangle : public Polygon {
public:
    int area() override {
        return (width * height) / 2;
    }
};

int main() {
    Polygon *poly1;
    Rectangle rect;
    Triangle tri;
    int choice, width, height;

    cout << "Choose a shape to calculate area:\n";
    cout << "1. Rectangle\n";
    cout << "2. Triangle\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter width: ";
    cin >> width;
    cout << "Enter height: ";
    cin >> height;

    if (choice == 1) {
        poly1 = &rect;
    } else if (choice == 2) {
        poly1 = &tri;
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    poly1->set_values(width, height);
    cout << "The area is: " << poly1->area() << endl;

    return 0;
}
