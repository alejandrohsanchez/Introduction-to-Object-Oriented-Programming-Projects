/*
Create a function that returns the next value in a Fibonacci sequence every time
you call it. Add an argument that is a bool with a default value of false such
that when you give the argument with true it "resets" the function to the beginning
of the Fibonacci sequence. Exercise this function in main().
*/

#include <iostream>
using namespace std;

int fibonacci(bool arg = false);

int fibonacci(bool arg) {
    static int nextVal;
    static int x = 0;
    static int y = 1;
    static int count = 1;

    if (arg == true) {
        x = 0;
        y = 1;
        count = 1;
        return x;
    }

    if (count == 1) {
        count++;
        return x;
    }

    if (count == 2) {
        count++;
        return y;
    }

    nextVal = x + y;
    x = y;
    y = nextVal;

    return nextVal;
}

int main() {
    int i, N, reset;

    cout << "Enter how many numbers to print: ";
    cin >> N;
    cout << "Enter how many numbers until the sequence will reset: ";
    cin >> reset;
    cout << "\nFibonacci Sequence...\n" << endl;

    for (i = 0; i < N; i++) {
        cout << fibonacci() << " ";
        if (i == reset-1) {
            fibonacci(true);
        }
    }
    cout << endl;

    return 1;
}