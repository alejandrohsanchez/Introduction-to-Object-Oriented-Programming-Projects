#include <iostream>

using namespace std;

int main() {
    // Declaring the radius (r) and area (A) variables.
    double r, A;

    // Take user input and store the value in r
    cout << "Please enter the radius: ";
    cin >> r;

    // Computing the area of the circle and assigning the value to A.
    A = 3.1415 * r * r;

    // Printing out the area of the circle in a sentence.
    cout << "The area of the circle is: " << A << endl;
    return 1;
}