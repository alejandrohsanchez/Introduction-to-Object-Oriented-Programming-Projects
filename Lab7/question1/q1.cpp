/*
Create a function with a static variable that is a pointer (with a
default argument of zero). When the caller provides a value for this
argument it is used to point at the beginning of an array of int.
If you call the function with a zero argument (using the default
argument), the function returns the next value in the array, until
it sees a "-1" value in the array (to act as an end-of-array
indicator). Exercise this function in main().
*/


#include <iostream>
using namespace std;

// Function with static variable
int f(int* p = 0);

int f(int* p) {
    static int* nextPoint;

    if (p != NULL) {
        nextPoint = p;
        return *nextPoint;
    }
    
    if (*nextPoint == -1) {
        return -1;
    }

    return *nextPoint++;
}

int main() {
    
    int i;
    int array [] = {2, 4, 6, 8, 10, -1};

    f(array);
    i = f();

    while (i != -1) {
        cout << i << " ";
        i = f();
    }
    cout << endl;

    return 1;
}