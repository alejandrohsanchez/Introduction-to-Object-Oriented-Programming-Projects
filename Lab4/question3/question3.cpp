#include <iostream>
using namespace std;

/*
Create a class containing an array of int. Index through this
array using a pointer to member.
*/

class arrayIterate {
    public:
        int size = 5;
        int A[5]; // Array size must have a constant value.

        arrayIterate() {
            for (int i = 0; i < size; i++) {
                A[i] = i + 1;
            }
        }
};

int main() {
    arrayIterate x;

    cout << "The array has contents of:\n1, 2, 3, 4, 5." << endl;
    int (arrayIterate::*mp)[5] = &arrayIterate::A;

    cout << "Printing out contents of array:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << (x.*mp)[i] << " ";
    }
    cout << endl;
    return 1;
}