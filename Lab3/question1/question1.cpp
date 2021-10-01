#include <iostream>
using namespace std;
/*
Write two class, each of which has a member function that takes a pointer
to an object of the outher clas. Create instances of both in main() and
call the aforementioned member function in each class.
*/

class B;

class A {
    public:
        void f1(B *);
        void g1() {
            cout << "This is class A." << endl;
        }
};

class B {
    public:
        void f2(A *);
        void g2() {
            cout << "This is class B." << endl;
        }

};

void A::f1(B *pointerB) {
    pointerB->g2();
}

void B::f2(A *pointerA) {
    pointerA->g1();
}

int main() {
    A pointerA;
    B pointerB;

    // This will print "This is class B."
    pointerA.f1(&pointerB);

    // This will print "This is class A."
    pointerB.f2(&pointerA);

    return 1;
}