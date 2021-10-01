#include <iostream>
#include "Handle.h"

using namespace std;

struct Handle::Cheshire {
    int i;
};

void Handle::initialize() {
    smile = new Cheshire;
    smile->i = 0;
}

void Handle::cleanup() {
    delete smile;
    cout << "Smile has been deleted in cleanup..." << endl;
}

int Handle::read() {
    return smile->i;
}

void Handle::change(int x) {
    smile->i = x;
}

void Handle::printOut() {
    cout << "The current value is: " << smile->i << endl;
}

void Handle::setValue() {
    cout << "Enter a value: ";
    cin >> smile->i;
}

void Handle::resetValue() {
    smile->i = 0;
    cout << "Value has been reset..." << endl;
}