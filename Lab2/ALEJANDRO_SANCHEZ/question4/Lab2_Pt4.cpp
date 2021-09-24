#include <iostream>

using namespace std;

char* callTo(char* a, int size) {
    // Dynamic declaration.
    char *newArray = new char;
    int i;
    /*
    Using array indexing, copy the characters from the
    argument to the dynamically allocated array and
    returning the pointer to copy. In my program, my copy
    array is defined as copyArr.
    */
    for (i = 0; i < size; i++) {
        *(newArray + i) = *(a + i);
    }
    
    return newArray;
}

int main() {
    int size = 3;
    /*
    Using new to dynamically allocate an array of char that
    that is passed to the function.
    */
    char *copyArr = new char;

    /*
    Creating and passing a static quoted character array,
    then taking the result of the callTo function and
    passing it to callTo. It will be returned to the
    copyArr pointer.
    */
    char arr [] = {'a', 'b', 'c', '\0'};
    char *arr2 = new char;
    // Dynamic array that will hold return array from callTo.
    copyArr = callTo(arr, size);

    // Printing original array's contents.
    int i;
    cout << "Original Array's Contents:" << endl;
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nMemory address of original array:\n" << &arr << "\n" << endl;

    // Proving that copyArr holds arr contents.
    cout << "Copy Array's Contents:" << endl;
    for (int i = 0; i < size; i++) {
        cout << *(copyArr + i) << " ";
    }

    cout << "\nMemory address of copy array (pointer):\n" << &copyArr << endl;
    
    /*
    Deleting copyArr and arr2 to clean up all the
    dynamic storage.
    */
    delete copyArr;
    delete arr2;
    return 1;
}