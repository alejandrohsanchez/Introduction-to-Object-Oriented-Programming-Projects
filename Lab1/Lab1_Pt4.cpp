#include <iostream>

using namespace std;

int main() {
    // Creating an array of numbers of specified range
    int i, j, N = 100, arr[N];
    for (i = 0; i < N; i++) {
        if (i != 0 && i != 1) {
            arr[i] = i;
        }
    }

    // Detecting prime numbers with 2 for loops
    for (i = 0; i < N; i++) {
        for (j = 2; j <= arr[i]/2; j++) {
            // Check if not prime
            if (arr[i] % j == 0) {
                // If the number is prime set it to 0
                arr[i] = 0;
            }
        }
    }
    
    // Printing all prime numbers
    for (i = 0; i < N; i ++) {
        if (arr[i] != 0) {
            cout << arr[i] << " ";
        }
    }
    
    return 1;
}