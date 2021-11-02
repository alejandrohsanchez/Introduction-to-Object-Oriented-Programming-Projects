/*
Create a class that holds an array of ints. Set the size of the array using static const int inside the class.
Add a const int variable, and initialize it in the constructor initializer list; make the constructor inline.
Add a static int member variable and initialize it to a specific value. Add a static member function that
prints the static data member. Add an inline member function called print() to print out all the values in
the array and to call the static member function. Exercise this class in main().
*/

#include <iostream>
using namespace std;

class A {
    // Setting the size of the array using static const int.
    static const int size = 5;

    // Adding array of ints.
    int array[size] = {1, 2, 3, 4, 5};

    // Declaring const int variable.
    const int variable;

    public:
        A():variable(1) {}
        static int memberVariable;

        static void printStaticDataMember();

        inline void printArrayContents();

};

// Initializing const int variable.
int A::memberVariable = 3;

// Inline member function that will print out all the values in the array.
void A::printArrayContents() {
    int i;
    for (i = 0; i < size; i++) {
        cout << array[i];
    }
    cout << endl;
}

// Static member function to print static data member.
void A::printStaticDataMember() {
    cout << memberVariable << endl;
}

int main() {
    A a;

    a.printStaticDataMember();
    a.printArrayContents();

    return 0;
}