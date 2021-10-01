#include <iostream>
using namespace std;

/*
Modify Exercise 6 so that Nest and Egg each contain private data. Grant
friendship to allow the enclosing classes access to this private data.
*/

class Nest {
    public:
        Nest() {}
        void printNest() {
            cout << "Printing from Nest." << endl;
        }

        class Hen {
            public:
                Hen() {}
                void printHen() {
                    cout << "Printing from Hen." << endl;
                }

                class Egg {
                    public:
                        Egg() {}
                        void printEgg() {
                            cout << "Printing from Egg." << endl;
                        }
                };
        };
};

int main() {
    Nest n;
    Nest::Hen h;
    Nest::Hen::Egg e;

    n.printNest();
    h.printHen();
    e.printEgg();

    return 0;
}