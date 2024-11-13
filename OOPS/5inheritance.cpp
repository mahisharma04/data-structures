#include <iostream>
using namespace std;

class NarutoVerse{
private:
    //Under private the data is encapsulated and cannot be directly accessed.
    //A way to access them would be through the methods of this class, we can create getter and setter methods for that.
    string name;
    string speciality;
    string village;
    int age;

public:
    //Constructor (initializer list)
    NarutoVerse(string nm, string vlg, int a, string sp) : name(nm), speciality(sp), village(vlg), age(a) {}

    void setName(string n)
    {
        name = n;
    }
    string getName()
    {
        return name;
    }

    void setVillage(string v)
    {
        village = v;
    }
    string getVillage()
    {
        return village;
    }

    void setSpeciality(string s)
    {
        speciality = s;
    }
    string getSpeciality()
    {
        return speciality;
    }

    void setAge(int a)
    {
        //You can also put conditions here!
        if(a >= 0){
            age = a;
        }

        //age will only be set if its zero or more.
    }
    int getAge()
    {
        return age;
    }

    void introduceYourself(){
        cout << "Hi! I am " << name << " from " << village << ". It's nice to meet you!" << endl;
    }
};

class Jinchuuriki : public NarutoVerse{
public:
    string hostOfTailedBeast;

    Jinchuuriki( string nm, string vlg, int a, string sp, string host) : NarutoVerse(nm, vlg, a, sp), hostOfTailedBeast(host) {}
};

int main()
{

    NarutoVerse gaara = NarutoVerse("Gaara", "Sunagakure", 32, "Sand Manipulation");
    NarutoVerse nagato = NarutoVerse("Nagato Uzumaki", "Amegakure", 35, "Rinnegan");

    Jinchuuriki naruto = Jinchuuriki("Naruto Uzumaki", "Konohagakure", 29, "Six Paths Sage Jutsu", "Kurama");

    cout << naruto.getName() << endl;



    return 0;
}