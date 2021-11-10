/*
Problem 1. Create a class that contains an array of char. Add an inline constructor that uses the Standard C library function memset() to initialize the array to the constructor
argument (default this to ' '), and an inline member function called print() to print out all the characters in the array.
*/

#include <iostream>
#include <cstring> // Used for memset().
using namespace std;

class charArray {
    int size = 10;
    char array[10];

    public:
        // Inline constructor to initialize the array with memset().
        charArray(char c = ' ') {memset(array, c, size);}

        void print() {for (int i = 0; i < size; i++) {cout << charArray[i] << ' ';} cout << endl;}
};

int main() {

    return 1;
}