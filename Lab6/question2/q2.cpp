/*
Create a vector<Counted*> and fill it with pointers to new Counted objects (from Exercise 1). Move through the vector and print the Counted objects, then
move through again and delete each one.
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
};

// Count = 1 when first object is created.
int Counted::count = 1;

int main() {
    int i;

    // Creating vector object
    vector<Counted*> a;
    
    // Filling vector with new Counted objects. This prints out the objects.
    for (i = 0; i < 26; i++) {
        a.push_back(new Counted);
    }

    // Moving through again and deleting each one.
    for (i = 0; i < 26; i++) {
        delete a[i];
    }
    
    return 1;
}