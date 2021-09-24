#include <iostream>
#include <cstdlib>

using namespace std;

string toBinary(const unsigned char val, string arr[]) {
    string temp = "";
    for (int i = 7; i >= 0; i--) {
        if (val & (1 << i)) {
            temp += "1";
        }
        else {
            temp += "0";
        }
    }
    temp += " ";
    return temp;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Must provide a number" << endl;
        exit(1);
    }
    double d = atof(argv[1]);
    unsigned char* cp = reinterpret_cast<unsigned char*>(&d);
    string arr [8];
    string tmp;
    int i;
    for (i = sizeof(double); i > 0; i -= 2) {
        tmp = "";
        tmp += toBinary(cp[i - 1], arr);
        arr[8 - (i / 2)] = tmp;
        tmp += toBinary(cp[i], arr);
        arr[8 - (i / 2)] = tmp;
    }

    for (i = 4; i < 8; i++) {
        cout << arr[i];
    }
    cout << "" << endl;
    
    return 1;
}