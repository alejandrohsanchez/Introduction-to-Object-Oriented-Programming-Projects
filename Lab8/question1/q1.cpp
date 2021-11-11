/*
Problem 1. Create a class that contains an array of char. Add an inline constructor that uses the Standard C library function memset() to initialize the array to the constructor
argument (default this to ' '), and an inline member function called print() to print out all the characters in the array.
*/

#include <iostream>
#include <cstring> // Used for memset().
using namespace std;

class charArray {
    char var;
    enum size {N = 5};
    char array[N];

    public:
        void setChar(char c) {var = c;}
        // Inline constructor to initialize the array with memset().
        charArray(char c = ' ') {memset(array, c, N); cout << "Initialized with memset()..." << endl;}
        
        // Inline member function.
        void print() {cout << "Printing '" << var << "' " << N << " time(s):" << endl; for (int i = 0; i < N; i++) {cout << array[i] << ' ';} cout << endl;}
};

int main() {
    char character;
    int numba;

    cout << "Enter a character: "; cin >> character;
    charArray A(character);
    A.setChar(character);
    A.print();

    return 1;
}