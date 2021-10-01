#include <iostream>
#include "Handle.h"
#include "Handle.cpp"

using namespace std;

int main() {
    Handle u;
    u.initialize();
    u.read();
    u.change(1);
    //u.cleanup();

    u.printOut();
    u.setValue();
    u.printOut();
    u.resetValue();
    u.setValue();
    u.printOut();
    u.cleanup();
    return 0;
}