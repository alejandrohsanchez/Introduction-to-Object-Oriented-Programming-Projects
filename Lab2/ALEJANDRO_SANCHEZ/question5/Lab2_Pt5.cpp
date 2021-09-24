#include <iostream>

using namespace std;

struct listA {
    int size;
    struct listA *sp;
};

void makeChain(struct listA *head, int length) {
    int i;
    struct listA *copy = head;

    for (i = 1; i <= length; i++) {
        listA *tail = new listA();
        tail->sp = NULL;
        tail->size = i;

        if (i == 1) {
            head->size = i;
        }
        else {
            while (copy->sp != NULL) {
                copy = copy->sp;
            }
            copy->sp = tail;
        }
    }

}

void printList(struct listA *head) {
    struct listA *copy = head;
    while (copy != NULL) {
        cout << copy << "\t" << copy->size << endl;
        copy = copy->sp;
    }

}


int main() {
    listA *head = new listA();
    makeChain(head, 10);

    cout << "Addresses\tData" << endl;
    printList(head);

    return 1;
}