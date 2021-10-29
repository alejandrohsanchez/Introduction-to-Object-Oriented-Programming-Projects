/*
Create a class with an overloaded operator new and delete, both the single-object versions and the array versions.
Test both versions.
*/

#include <iostream>
#include <cstdlib>
#include <new>

using namespace std;

class A {
    int x;
    static int count;
    public:
        A():x(count++) {
            cout << "Creating 'A', x = " << x << endl;
        }

        ~A() {
            cout << "Destructing 'A', x = " << x << endl;
        }

        // single-object version
        void* operator new(size_t size) {
            cout << "A::operator new" << endl;
            void* a = malloc(size);
            return a;
        }

        void operator delete(void* a) {
            cout << "A::operator delete" << endl;
        }

        // array version
        void* operator new[](size_t size) {
            cout << "A::operator new[]" << endl;
            return ::new int[size];
        }

        void operator delete[](void* a) {
            cout << "A::operator []delete" << endl;
            ::delete []a;
        }

};

int A::count = 0;

int main() {
    A *a = new A;
    A *b = new A[26];
    
    delete a;
    delete []b;

    return 1;
}