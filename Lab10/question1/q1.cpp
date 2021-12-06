/*
1. [Exercise 1 on Page 62] Sometimes the input from a file stream contains a two-character sequence to represent a
newline. These two characters (0x0a 0x0d) produce extra blank lines when the stream is printed to standard out.
Write a program that finds the character 0x0d (ASCII carriage return) and deletes it from the string. [20 pts]

*/

#include <iostream>

using namespace std;
//Code will remove any spaces caused by \r
//as \r ASCII carriage return is 0x0d
int main(){
    // Creates spacing with \r
    string sentence = "Mar\ry ha\rd a li\rtt\rl\re la\rm\rb.";
    cout << sentence << endl;
    int size = sentence.size();

    cout << "Process begins:" << endl;
    for (int i = 0; i < size; i++){
        if (sentence[i] == 0x0d){
            // Erasing spacing detected in a string. Using sentence.erase to remove spacing and sentence.begin to start at the beginning of the string.
            sentence.erase(sentence.begin() + i);
            cout << sentence << endl;
            size--;
        }
    }
    cout << endl;

    cout << "String after removing carriages: " << sentence << endl;
}
