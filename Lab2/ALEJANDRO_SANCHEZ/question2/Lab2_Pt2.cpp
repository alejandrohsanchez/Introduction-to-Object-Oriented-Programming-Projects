#include <iostream>

using namespace std;
/*
Define an array of int. take the starting address of that array
and use static_cast to convert it into a void*. Write a function
that takes a void*, a number (indicating a number of bytes), and
a value (indicating the value to which each byte should be set)
as arguments. The function should set each byte in the specified
range to the specified value. Try out the function on your array
of int.
*/

/*
The callTo function takes a void*, a number, and a value as arguments.
The function sets each byte in the specific range to the specific value.
*/
void callTo(void *vp, int byteNum, int byteVal) {
    int i;
    cout << "The values in void*:" << endl;
    for (i = 0; i < byteNum; i++) {
        *(&vp + (8*i)) = (void*)(i + 1);
        cout << *(&vp + (8 * i)) << endl;
    }
    
    cout << " " << endl;
    
    
}

int main() {
    int arr1[5] = {1, 2, 3, 4, 5};

    // Instantiating a pointer void* that points to int array arr1.
    void* vp[5];
    *vp = static_cast <void*>(&arr1);
    
    // This calls to the callTo function.
    callTo(&vp, 5, sizeof(&vp));
    
    int i;
    cout << "The values in int array:" << endl;
    for (i = 0; i < 5; i++) {
        cout << arr1[i] << endl;
    }
    
    return 1;
}
