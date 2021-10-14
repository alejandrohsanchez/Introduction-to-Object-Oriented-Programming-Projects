/*
In AddingVirtuals.cpp, make all the member functions of Pet
pure virtual, but provide a definition for name(). Fixe Dog
as necessary, using the base-class definition of name().
*/

#include <iostream>
#include <string>
using namespace std;

class Pet {
    string pname;
    public:
        Pet(const string& petName) : pname(petName) {}
        virtual string name() const { return pname; }
        virtual string speak() const {return ""; }
};

class Dog : public Pet {
    string name;
    public:
        Dog(const string& petName) : Pet(petName) {}
        virtual string sit() const {
            return Pet::name() + " sits";
        }
        
        string speak() const {
            return Pet::name() + " says 'Bark!'";
        }
};

int main() {
    Pet* p[] = {new Pet("generic"), new Dog("bob")};
    cout << "p[0]->speak() = "
         << p[0]->speak() << endl;
    cout << "p[1]->speak() = "
         << p[1]->speak() << endl;
    return 1;
}