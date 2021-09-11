#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int i;
    bool x = true;
    while (x) {
        
        cin >> s;

        if (s == "smile" || s == "happy" || s == "laugh" || s == "bright") {
            i = 2;
        }

        else if (s == "sad" || s == "hurt" || s == "upset" || s == "cry") {
            i = 1;
        }

        else if (s == "exit") {
            i = 0;
        }
        else {
            i = 3;
        }

        switch (i) {
            case 2:
                cout << "are you feeling happy today?" << endl;
                break;
            case 1:
                cout << "are you down? You need therapy?" << endl;
                break;
            case 0:
                cout << "going so soon?" << endl;
                x = false;
                break;
            default:
                cout << "bruh" << endl;

        }
    }

    return 1;
}