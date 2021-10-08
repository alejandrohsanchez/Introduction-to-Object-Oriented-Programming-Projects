#include <iostream>
using namespace std;

/*
Write a function that takes a pointer argument, modifies what
the pointer points to, and then returns the destination of
the pointer as a reference. 
*/

void swapping(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main() {
    int x, y;
    cout << "Enter a value for variable x: "; cin >> x;
    cout << "Enter a value for variable y: "; cin >> y;
    cout << "\n\nReviewing...\n" << endl;
    cout << "Data:\nx = " << x << "\nAddress of x = " << &x << endl;
    cout << "y = " << y << "\nAddress of y = " << &y << endl;
    
    cout <<"\n\nSwapping...\n" << endl;
    swapping(&x, &y);

    cout << "Data (after swap):\nx = " << x << "\nAddress of x = " << &x << endl;
    cout << "y = " << y << "\nAddress of y = " << &y << endl;


}