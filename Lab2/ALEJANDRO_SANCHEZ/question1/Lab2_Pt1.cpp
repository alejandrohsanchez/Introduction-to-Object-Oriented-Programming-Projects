#include <iostream>

using namespace std;

/*
This struct holds two string objects and one int. Using a
typedef for the struct name, this creates an instance of
the struct "threeObj" and initializes all three values in
the instance. They are printed out in main.
*/
typedef struct threeObj {
    // Objects str1, str2, and int.
    string str1 = "String 1";
    string str2 = "String 2";
    int num = 2;

};

int main() {
    threeObj object1;
    cout << "First string: " << object1.str1 << "\nSecond string: " << object1.str2 << "\nInteger: " << object1.num << endl;
    
    /*
    Using a pointer to point to the instance of struct
    threeObj.
    */
    threeObj* sp = &object1;
    sp->str1 = "Edited String 1";
    sp->str2 = "Edited String 2";
    sp->num = 20;

    cout << "\nFirst string: " << sp->str1 << "\nSecond string: " << sp->str2 << "\nInteger: " << sp->num << endl;
    
    return 1;
}