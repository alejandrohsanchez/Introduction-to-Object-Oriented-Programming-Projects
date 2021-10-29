/*
Create a class with a placement new with a second argument of type string. The class should contain
a static vector<string> where the second new argument is stored. The placement new should allolcate
storage as normal. In main(), make calls to your placement new with string arguments that describe
the calls (you may want to use the preprocessor's __FILE__ and __LINE__ macros).
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

#define S(x) #x
#define S_(x) S(x)
#define S__LINE__ S_(__LINE__)

using namespace std;

class A {
    static vector<string> V;
    public:
        A() {
            cout << "New object created!" << endl;
        }
        
        ~A() {
            cout << "Object is deconstructed!" << endl;
        }
        
        void* operator new(size_t size, string arg) {
            V.push_back(arg);
            void* a = malloc(size);
            
            return a;
        }

        static void print() {
            for (int i = 0; i << V.size(); i++) {
                cout << V[i] << endl;
            }
        }
};

vector<string> A::V;

int main() {
    A *a = new(__FILE__) A;
    A *b = new(S__LINE__) A;
    A *c = new("A string argument") A;
    
    a->print();
    b->print();
    c->print();

    delete c;
    delete b;
    delete a;

    return 1;
}