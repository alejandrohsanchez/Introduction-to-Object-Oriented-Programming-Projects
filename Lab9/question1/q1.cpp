/*
Create a base class X with a signle constructor that takes an int argument and a member function f(), that
takes no arguments and returns void. Now inherit X into Y and Z, creating constructors for each of them
that takes a single int argument. Now multiply inherit Y and Z into A. Create an object of class A,
and call f() for that object. Fix the problem with explicit disambiguation.
*/

#include <iostream>

class X {
    int x;
    public:
        X(int xxx) : x(xxx) {}
        void f() {std::cout << "f() called from X class" << std::endl;}
};

class Y : public X {
    int y;
    public:
        Y(int yyy) : X(yyy), y(yyy) {}
        void f() {std::cout << "f() called from Y class" << std::endl;}
};

class Z : public X {
    int z;
    public:
        Z(int zzz) : X(zzz), z(zzz) {}
        void f() {std::cout << "f() called from Z class" << std::endl;}
};

class A : public Y, public Z {
    int a;
    public:
        using Z::f;
        A(int aaa) : Y(aaa), Z(aaa), a(aaa) {}
};

int main() {
    A a(10);
    a.f();

    return 1;
}