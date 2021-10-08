#include <iostream>
using namespace std;

/*
Modify C14:Combined.cpp so that f() is virtual in the base class.
Change main() to perform an upcast and a virtual call.
*/

class A {
    int i;
    public:
        A(int ii) : i(ii) {}
        ~A() {}
        virtual void f() const {
            cout << "Original value from class A: " << i << endl;
        }
};

class B {
    int i;
    public:
        B(int ii) : i(ii) {}
        ~B() {}
        virtual void f() const {
            cout << "This is the value accessed from class B: " << (i + i) << endl;
        }
};

class C : public B {
    A x;
    public:
        C(int ii) : B(ii), x(ii) {}
        ~C() {}
        virtual void f() const {
            x.f();
            B::f();
        }
};

int main() {
    int val;
    cout << "Enter the value: " << endl; cin >> val;
    C c(val);
    cout << "Upcast to virtual call..." << endl;
    B *pB = &c;
    pB->f();
}