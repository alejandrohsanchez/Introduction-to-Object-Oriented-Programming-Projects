#include <iostream>
#include "Part3.h"

using namespace std;

// Defining the sum, half, capitalize, and irrational functions.
int sum(int x, int y) {
    cout << "sum, int x, int y, int" << endl;
    return x + y;
}

double half(double x) {
    cout << "half, double x, double" << endl;
    return x / 2;
}

char capitalize(char x) {
    cout << "capitalize, char x, char" << endl;
    return x - 32;
}

float irrational(float x) {
    cout << "irrational, float x, float" << endl;
    return x * 3.1415;
}
