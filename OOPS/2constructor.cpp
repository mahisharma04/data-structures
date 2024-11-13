#include <iostream>
using namespace std;

class NarutoVerse{
public:
    string name;
    string speciality;
    string village;
    int age;

    //Constructor (initializer list)
    NarutoVerse(string nm, string vlg, int a, string sp) : name(nm), speciality(sp), village(vlg), age(a) {}

    void introduceYourself(){
        cout << "Hi! I am " << name << " from " << village << ". It's nice to meet you!" << endl;
    }
};

int main()
{

    NarutoVerse naruto = NarutoVerse("Naruto Uzumaki" , "Konohagakure", 29, "Rasengan");
    NarutoVerse gaara = NarutoVerse("Gaara", "Sunagakure", 32, "Sand Manipulation");
    NarutoVerse nagato = NarutoVerse("Nagato Uzumaki", "Amegakure", 35, "Rinnegan");

    naruto.introduceYourself();

    return 0;
}