/*
Repeat Exercise 4, but add a member function f() to Counted that prints a message. Move through the vector and call f() for each object.
*/

#include <iostream>
#include <vector>
using namespace std;

class Counted {
    int id;
    static int count;

    public:
        // Constructor
        Counted():id(count++) {
            cout << "Creating 'Counted', id = " << id << endl;
        }
        // Destructor
        ~Counted() {
            cout << "Destructing 'Counted', id = " << id << endl;
        }

        void f() {
            cout << "This is a message printing from id " << id << endl;
        }
};

// Count = 1 when first object is created.
int Counted::count = 1;

int main() {
    int i;

    // Creating vector object
    vector<Counted*> a;
    
    // Filling vector with new Counted objects
    for (i = 0; i < 26; i++) {
        a.push_back(new Counted);
    }

    for (i = 0; i < 26; i++) {
        a[i]->f();
    }
    // Moving through again and deleting each one.
    for (i = 0; i < 26; i++) {
        delete a[i];
    }
    
    return 1;
}