/*
3. [Exercise 10 on Page 260] Use a stack<int> and build a Fibonacci sequence on the stack. The program’s
command line should take the number of Fibonacci elements desired, and you should have a loop that looks at the
last two elements on the stack and pushes a new one for every pass through the loop. [35 pts]

*/

#include <iostream>
#include <stack>

using namespace std;

int main(){
    int value;

    cout << "Enter value that will display after '0 1' in Fibonacci seires: "; cin >> value;
    int size = value, first = 0, second = 1;

    stack <int>stack;
    stack.push(0);
    stack.push(1);
    
    // Start creating series in the stack.
    while (value > 0){
        int next = first + second;
        
        stack.push(next);
        first = second;
        second = next;
        value--;
    }
    
    cout << "Fibonacci series on the stack: ";
    int arr[25], i = 0;
    
    // Check if the stack contains any more values to add.
    while(!stack.empty()){
        arr[i] = stack.top();
        stack.pop();
        i++;
        value--;
    }

    for(int i = size + 1; i >= 0; i--){
        cout << arr[i] << " ";   
    }

    cout << endl;
    return 0;
}