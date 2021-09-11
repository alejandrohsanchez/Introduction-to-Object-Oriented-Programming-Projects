#include <iostream>
#include "Part3.h"

using namespace std;

int main() {
    if (sum(1, 1)) {
        // This will display the definition of 'sum'
        cout << "The function is called 'sum'. The argument list is 'int x, int y', and the return type is 'int'." << endl;
        //cout << sum(1,1) << endl;
    }

    if (half(1)) {
        // This will display the definition of 'half'
        cout << "The function is called 'half'. The argument list is 'double x', and the return type is 'double'." << endl;
        //cout << half(20) << endl;
    }

    if (capitalize('a')) {
        // This will display the definition of 'capitalize'
        cout << "The function is called 'capitalize'. The argument list is 'char x', and the return type is 'char'." << endl;
        //cout << capitalize('a') << endl;
    }

    if (irrational(1.234)) {
        // This will display the definition of 'irrational'
        cout << "The function is called 'irrational'. The argument list is 'float x', and the return type is 'float'." << endl;
        //cout << irrational(1.234) << endl;
    }
    return 1;
}