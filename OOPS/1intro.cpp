#include <iostream>
using namespace std;

class NarutoVerse{
public:
    string name;
    string speciality;
    string village;
    int age;


    void introduceYourself(){
        cout << "Hi! I am " << name << " from " << village << ". It's nice to meet you!" << endl;
    }
};

int main()
{

    NarutoVerse naruto;

    naruto.name = "Naruto Uzumaki";
    naruto.age = 29;
    naruto.village = "Konohagakure";
    naruto.speciality = "Rasengan";

    NarutoVerse gaara;

    gaara.name = "Gaara";
    gaara.age = 32;
    gaara.village = "Sunagakure";
    gaara.speciality = "Sand manipulation";

    naruto.introduceYourself();
    gaara.introduceYourself();
    return 0;
}