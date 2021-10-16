/*
Create a class with (at least four) data members and (at least two)
virtual functions. Write a function that looks at the memory in an object
of your class and prints out the various pieces of it. To do this you will
need to experiment and iteratively discover where the VPTR is located in the object.
*/

#include <iostream>
using namespace std;

/*
Creating a class with at least 4 data members.
*/
class Base {
    public:
        int a, b, c, d;
        Base() {
            a = 1;
            b = 2;
            c = 3;
        }
        
        /*
        At least 2 virtual functions
        */
        virtual void show() { cout << "Base::show" << endl; }

        virtual void display() {
            cout << "Base::display\n"
                 << a << " "
                 << b << " "
                 << c << endl;
        }
};

/*
This is a derived class that will be accessed with a pointer.
*/
class Derived : public Base {
    public:
        int x, y, z;
        Derived() {
            x = 100;
            y = 200;
            z = 300;
        }
        virtual void show() { cout << "Derived::display" << endl; }

        virtual void display() {
            cout << "Derived::display\n"
                 << x << " "
                 << y << " "
                 << z << endl;
        }
};

int main() {
    Base A;
    Base *a;

    cout << "Pointer b will point to the base class 'Base'";
    a = &A;
    a->display();
    a->show();

    cout << "Pointer b will now point to data in the derived class 'Derived'";
    Derived B;
    a = &B;
    a->display();
    a->show();


    return 1;
}