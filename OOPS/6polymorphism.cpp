#include <iostream>
using namespace std;

//NOTE : The most common feature of polymophism is useful when a parent class pointer has to point to a child class.

class NarutoVerse{
private:
    //Under private the data is encapsulated and cannot be directly accessed.
    //A way to access them would be through the methods of this class, we can create getter and setter methods for that.
    string name;
    string village;
    int age;
public:
    //Constructor (initializer list)
    NarutoVerse(string nm, string vlg, int a) : name(nm), village(vlg), age(a) {}

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

    virtual void introduceYourself(){
        cout << "Hi! I am " << name << " from " << village << ". It's nice to meet you!" << endl;
    }
};

class Jinchuuriki : public NarutoVerse{
public:
    string hostOfTailedBeast;
    Jinchuuriki( string nm, string vlg, int a, string host) : NarutoVerse(nm, vlg, a), hostOfTailedBeast(host) {}

    void introduceYourself(){
        cout << "Hello! I am " << getName() << " from "<< getVillage() << ", host of " << hostOfTailedBeast << ". "<< endl;
    }
    
};

class TailedBeast{
public:
    int tails;
    string name;
    string speciality;
    string animal;
    //Constructor
    TailedBeast(int t, string nm, string ani, string sp) : tails(t) , name(nm), animal(ani), speciality(sp) {}

    void info(){
        cout << name << " is a " << tails << " tailed " << animal << "." << endl;
    }
};

int main()
{

    NarutoVerse gaara = NarutoVerse("Gaara", "Sunagakure", 32);
    NarutoVerse nagato = NarutoVerse("Nagato Uzumaki", "Amegakure", 35);

    Jinchuuriki naruto = Jinchuuriki("Naruto Uzumaki", "Konohagakure", 29, "Kurama");

    TailedBeast nineTails = TailedBeast(9, "Kurama" , "Fox", "Massive Chakra Reserve");
    TailedBeast eightTails = TailedBeast(8, "Gyuuki", "Octopus", "Massive Chakra Reserve");
    TailedBeast sevenTails = TailedBeast(7, "Choumei", "Rhinoceros Beetle", "Immense Strength");
    TailedBeast sixTails = TailedBeast(6, "Saiken", "Slug", "Emmit Corrosive Substance");
    TailedBeast fiveTails = TailedBeast(5, "Kokuo", "Hybrid Animal", "Boil Release");
    TailedBeast fourTails = TailedBeast(4, "Son Goku", "Monkey", "Lava Release");
    TailedBeast threeTails = TailedBeast(3, "Isobu", "Aquatic Beast", "Coral Jutsu");
    TailedBeast twoTails = TailedBeast(2, "Matatabi", "Feline", "Immense Speed");
    TailedBeast oneTail = TailedBeast(1, "Shukaku", "Raccoon", "Sand Manipulation");


    NarutoVerse* n1 = &naruto;
    n1->introduceYourself();



    return 0;
}