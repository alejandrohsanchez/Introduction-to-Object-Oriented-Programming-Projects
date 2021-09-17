#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream in("Part2_Text.txt");
    string s, line;
    while (getline(in, line)) {
        //s += line + "\n";
        // To get all the text in all lines of a text file, remove the + "\n"
        s += line;
    }
    
    cout << s;

    return 1;
}