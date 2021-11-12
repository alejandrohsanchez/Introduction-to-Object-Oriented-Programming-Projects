/*
Write a class called Bird that contains a string member and static int. In the default constructor, use the int to
automatically generate an identifier that you build in the string, along with the name of the class
(Bird #1, Bird #2, etc.). Add an operator << for ostreams to print out the Bird objects. Write an assignment
operator = and a copy-constructor. In main(), verify that everything works correctly.
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;



class Bird {
    string member;
    static int identifier;
    friend ostream& operator << (ostream& os, const Bird& bird);

    public:
        Bird() {
            // Building identifier.
            ostringstream stream;
            // Printing name of the class using operator <<  for ostreams to print out the Bird objects.
            stream << "Class 'Bird' #" << identifier++;
            member = stream.str();
        }

        // Copy constructor.
        Bird(const Bird& bird) {
            // Assignment operator.
            member = bird.member;
            identifier++;
        }

        ~Bird() {
            identifier--;
        }

};

ostream& operator << (ostream& stream, const Bird& bird) {
    return stream << bird.member;
}

int Bird::identifier = 1;

int main() {
    Bird one;
    Bird two;
    Bird three;
    Bird four;
    Bird five;

    cout << "Bird one\t|\tBird two\t|\tBird three\t|\tBird four\t|\tBird five\n"
         <<  one << "\t|\t" << two << "\t|\t" << three << "\t|\t" << four << "\t|\t" << five << endl;
    
    
    // Using copy constructor.
    three = two;
    cout << "\nUsing copy constructor to set 'Bird three' = 'Bird two'...\nBird three = " << three << endl;

    // Using copy constructor.
    one = five;
    cout << "Using copy constructor to set 'Bird one' = 'Bird five'...\nBird one = " << one << endl;

    return 1;
}