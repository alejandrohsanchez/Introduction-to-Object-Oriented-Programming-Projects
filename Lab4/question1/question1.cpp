#include <iostream>
using namespace std;

class Subject {
    public:
        virtual void f() = 0;
        virtual void g() = 0;
        virtual void h() = 0;
};

class Proxy : public Subject {
    Subject *sp;
    public:
        /*
        Using either implementation will be considered the dynamic
        characteristic of the program. Depending on which
        implementation the user chooses, the program will treat
        each void function differently. However, each implementation
        function can be treated as a unique routine that can be
        edited.
        */

        // Implementation 1 takes a pointer and points to Subject.
        public: Proxy(Subject *argPointer1 = 0) {
            sp = argPointer1;
        }
        
        // Implementation 2 takes a pointer and points to Subject.
        void implementedFunc(Subject *argPointer2) {
            sp = argPointer2;
        }

        void f() {
            sp->f();
        }
        void g() {
            sp->g();
        }
        void h() {
            sp->h();
        }
};

class Implementation1 : public Subject{
    public:
        void f() {
            cout << "Implementation 1 with subject installed, f function." << endl;
        }

        void g() {
            cout << "Implementation 1 with subject installed, g function." << endl;
        }
        
        void h() {
            cout << "Implementation 1 with subject installed, h function." << endl;
        }
};

class Implementation2 : public Subject {
    public:
        void f() {
            cout << "Implementation 2 with subject installed, f function." << endl;
        }

        void g() {
            cout << "Implementation 2 with subject installed, g function." << endl;
        }

        void h() {
            cout << "Implementation 2 with subject installed, h function." << endl;
        }
};

int main() {
    Implementation1 I1;
    Proxy proxy(&I1);
    proxy.f();
    proxy.g();
    proxy.h();

    Implementation2 I2;
    proxy.implementedFunc(&I2);
    proxy.f();
    proxy.g();
    proxy.h();

    return 1;
}