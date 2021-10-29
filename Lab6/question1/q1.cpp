/*
Create a class Counted that contains an int id and a static int count. The default constructor should begin: Counted() : id(count++).
It should also print its id and that it is being created. The destructor should print that it is being destroyed and its id. Test
your class.
*/

#include <iostream>
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

    // When new objects are created, id will increment.
    Counted *a = new Counted;
    delete a;
    Counted *b = new Counted;
    delete b;
    Counted *c = new Counted;
    delete c;
    Counted *d = new Counted;
    delete d;
    Counted *e = new Counted;
    delete e;
    Counted *f = new Counted;
    delete f;
    Counted *g = new Counted;
    delete g;
    Counted *h = new Counted;
    delete h;
    Counted *i = new Counted;
    delete i;
    Counted *j = new Counted;
    delete j;
    Counted *k = new Counted;
    delete k;
    Counted *l = new Counted;
    delete l;
    Counted *m = new Counted;
    delete m;
    Counted *n = new Counted;
    delete n;
    Counted *o = new Counted;
    delete o;
    Counted *p = new Counted;
    delete p;
    Counted *q = new Counted;
    delete q;
    Counted *r = new Counted;
    delete r;
    Counted *s = new Counted;
    delete s;
    Counted *t = new Counted;
    delete t;
    Counted *u = new Counted;
    delete u;
    Counted *v = new Counted;
    delete v;
    Counted *w = new Counted;
    delete w;
    Counted *x = new Counted;
    delete x;
    Counted *y = new Counted;
    delete y;
    Counted *z = new Counted;
    delete z;
    return 1;
}