#include <iostream>

using namespace std;

int main() {
    double r, A;

    cout << "Please enter the radius: ";
    cin >> r;
    A = 3.1415 * r * r;
    cout << "The area of the circle is: " << A << endl;
    return 1;
}