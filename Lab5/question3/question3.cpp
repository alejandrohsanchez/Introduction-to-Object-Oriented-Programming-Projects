/*
Write a class with one virtual function and one non- virtual function.
Inherit a new class, make an object of this class, and upcast to a
pointer of the base-class type. Use the clock() function found in <ctime>
(you’ll need to look this up in your local C library guide) to measure
the difference between a virtual call and non- virtual call. You’ll need
to make multiple calls to each function inside your timing loop in order
to see the difference.
*/

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Base{
    public:
        virtual void isvirtual();
        void nonvirtual();
};

class Derived: public Base {};

void Base::isvirtual() {}

void Base::nonvirtual() {}

double timer(Base* thing, void(Base::* pointed)()) {
    long time = 1000000000;
    clock_t start = clock();
    
    for (int i = 0; i < time; i++){
        (thing->*pointed)(); 
    }
    
    clock_t stop = clock();
    
    return static_cast<double>(stop - start) / CLOCKS_PER_SEC;
}

int main() {
    Derived thing;
    cout << timer(&thing, &Base::isvirtual) << endl;
    cout << timer(&thing, &Base::nonvirtual) << endl;
}