/*
1. Create a template that implements a singly-linked list called SList. Provide a default constructor, begin() and end()
functions (thus you must create the appropriate nested iterator), insert(), erase() and destructor.
*/

#include <iostream>
#include <list>
#include <string>
#include <cassert>

using namespace std;

template <class T>
class node {
    public:
        T data;
        node<T> *next;
};

template <class T>
class SList {        
        node<T> *head;
        node<T> *tail;
        
    public:
        SList() {
            head = NULL;
            tail = NULL;
            cout << "Calling constructor" << endl;
        }
        
        ~SList(){
            cout << "Calling Destructor" << endl;
        }
        
        T begin() {
            cout << "Starting singly-linked list." << endl;
            assert(head != NULL);
            return head->data;
        }
    
        T end() {
            cout << "Ending singly-linked list." << endl;
            assert(tail != NULL);
            return tail->data;
        }
        
        void insert(T const& num) {
            node<T> *temp = new node<T>;
            temp->data = num;
            temp->next = NULL;
            
            if(head == NULL) {
                head = temp;
                tail = temp;
            } else {
                tail->next = temp;
                tail = tail->next;
            }
        }

        void erase() {
            if(head == NULL) {
                cout << "Singly-linked list is erased" << endl;
                return;
            }
            
            node<T> *temp = new node<T>;
            temp = head;
            
            int iterations = 1;
            int max = 5;
            
            while(temp != NULL) {
                temp = temp->next;
                iterations++;
                if(iterations == max) {
                    free(temp);
                    return;
                }
            }
        }

        void display() {
            node<T> *temp = new node<T>;
            temp = head;
            cout << "Inside the singly-linked list" << endl;
            
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
};


int main()
{
    SList<int> singlyLinkedList;
    singlyLinkedList.insert(1);
    singlyLinkedList.insert(2);
    singlyLinkedList.insert(3);
    cout << "Calling display" << endl;
    singlyLinkedList.display();
    
    cout << std::endl << singlyLinkedList.begin() << endl;
    cout << singlyLinkedList.end() << endl;
    
    cout << "The 3rd element is deleted." << endl;

    cout << "Calling erase" << endl;
    singlyLinkedList.erase();
    cout << "Calling display" << endl;
    singlyLinkedList.display();

    cout << std::endl << std::endl << endl;

    return 0;
}