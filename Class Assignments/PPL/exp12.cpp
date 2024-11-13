#include <iostream>
#include <string>
using namespace std;

class Item {
protected:
    string title;
    float price;
public:
    void getdata() {
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter price: ";
        cin >> price;
    }
    
    void displaydata() const {
        cout << "Title: " << title << endl;
        cout << "Price: Rs." << price << endl;
    }
};

class Sale {
protected:
    float sales[3];
public:
    void getdata() {
        cout << "Enter sales for three months: ";
        for (int i = 0; i < 3; ++i) {
            cin >> sales[i];
        }
    }
    
    void displaydata() const {
        cout << "Sales for three months: ";
        for (int i = 0; i < 3; ++i) {
            cout << sales[i] << " ";
        }
        cout << endl;
    }
};

class HwItem : public Item, public Sale {
public:
    void getdata() {
        cout << "\nEnter hardware item details:\n";
        Item::getdata();
        Sale::getdata();
    }
    
    void displaydata() const {
        cout << "\nHardware Item Details:\n";
        Item::displaydata();
        Sale::displaydata();
    }
};

class SwItem : public Item, public Sale {
public:
    void getdata() {
        cout << "\nEnter software item details:\n";
        Item::getdata();
        Sale::getdata();
    }
    
    void displaydata() const {
        cout << "\nSoftware Item Details:\n";
        Item::displaydata();
        Sale::displaydata();
    }
};

int main() {
    HwItem hardware;
    SwItem software;

    hardware.getdata();
    software.getdata();

    hardware.displaydata();
    software.displaydata();

    return 0;
}
