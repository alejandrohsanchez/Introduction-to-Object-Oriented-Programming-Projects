/*
Create a class with member functions that throw exceptions. Within this class, make a nested class to use
as an exception object. It takes a single char* as its argument; this represents a description string.
Create a member function that throws this exception. (State this in the function's exception
specification.) Write a try block that calls this function and a catch clause that handles the exception
by printing out its description string.
*/

#include <iostream>
#include <stdexcept> // Exception handling.

using namespace std;

class Name{
    string first;
    string last;
    public:
        class wrongInput : public exception{
            public:
                //exception message
                const char* message; 
                wrongInput(const char* err){
                    message = err;
                }
        };
        
        // Checks for an error based on the throw error.       
        Name(string _first, string _last)throw(wrongInput){
            first = _first;
            // Set the last name.
            setLast(_last);
        }
        
        //wanna set the year field and maybe throw an exception if year is invalid
        void setLast(string _last)throw(wrongInput){
            if(_last == " "){
                throw wrongInput("String cannot be ' '.");
            }
            // Collect the last name.
            last = _last;
        }
        
        string getFirst()const{
            return first;
        }
        string getLast()const{
            return last;
        }
};

int main(){
    //try catch block
    try{
        Name person1("Alejandro", "Sanchez");
        cout << "First Name: "<< person1.getFirst() << "\nLast Name: " << person1.getLast() << "\n" << endl;
        //catch clause
        cout <<"Set last name to ' '"<<endl;
        person1.setLast(" ");

        // This will not iterate if the catch executes when an error is detected.
        cout << "First Name: "<< person1.getFirst() << "\nLast Name: " << person1.getLast() << "\n" << endl;
    } catch(Name::wrongInput error) {
        cout << error.message << endl;
    }

    return 0;
}