/*
Repeat Exercise 5 using PStash
*/

#include <iostream>
#include <string>
#include "PStash.h"
using namespace std;

class Counted {
    int id;
    static int count;
    public:
        Counted():id(count++) {
            cout << "Created 'Counted', id = " << id << endl;
        }

        ~Counted() {
            cout << "Destructing 'Counted', id = " << id << endl;
        }

        void f() {
            cout << "This is a message printing from id " << id << endl;
        }
};

int Counted::count = 0;

int main() {
    int i;

    PStash stash;

    // Filling vector with new Counted objects
    for (i = 0; i < 26; i++) {
        stash.add(new Counted);
    }

    cout << "stash created " << stash.count() << " objects" << endl;

    // Printing a message using f()
    for (i = 0; i < 26; i++) {
        ((Counted*)stash[i])->f();
    }

    // Moving through again and deleting each one.
    for (i = 0; i < 26; i++) {
        delete (Counted*)stash.remove(i);
    }

    return 1;
}