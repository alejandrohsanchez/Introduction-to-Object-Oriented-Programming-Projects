#include <iostream>
#include <string>

using namespace std;

int main() {
    // string s is  the string variable that will hold the user response.
    string s;
    
    // int i is the integral value variable. The integral value will be stored here after the user inputs their word.
    int i = 3;

    // This bool x variable keeps the program running as long as it is true.
    bool x = true;
    while (x) {
        
        // User input.
        cin >> s;

        // These are the happy emotions - words that will cause i to be reassigned to 1.
        if (s == "smile" || s == "happy" || s == "laugh" || s == "bright" || s == "joyful" || s == "love" || s == "sweet" || s == "romance") {
            i = 2;
        }

        // These are the sad emotions - words that will cause i to be reassigned to 2.
        else if (s == "sad" || s == "hurt" || s == "upset" || s == "cry" || s == "depressed" || s == "scared" || s == "stressed" || s == "fear" || s == "evil") {
            i = 1;
        }

        // If the user enters 'exit' then the program will end by assigning i to 0.
        else if (s == "exit") {
            i = 0;
        }
        else {
        
        // If none of the previous if conditions iterate, then i will remain as 3.
        }

        switch (i) {
            // If i is 2 (positive word), print out the following.
            case 2:
                cout << "Yay! You are being positive! Good emotions!" << endl;
                break;
            // If i is 1 (negative word)
            case 1:
                cout << "Oh no. Feel better soon! Stay positive." << endl;
                break;
            // If i is 0 (exit word)
            case 0:
                cout << "Leaving already? Bye-bye!" << endl;
                // This will trigger the program to end since the loop is driven by the status of x.
                x = false;
                break;
            // This will only iterate if the user entered a word that was considered not positive or negative.
            default:
                cout << "Unrecognizable word... Try again!" << endl;
                break;
        }
        // This resets i so that the switch will default to the default statement.
        i = 3;
    }

    // This is outside the while loop. End of program.
    return 1;
}