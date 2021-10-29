/*
Repeat Exercise 5 using PStash
*/

#ifndef PSTASH_H
#define PSTASH_H

class PStash {
    int quantity;
    int next;
    void** storage;
    public:
        PStash() : quantity(0), storage(0), next(0) {}
        int count() const { return next; }
        
        int add(void* element) {
            const int inflateSize = 10;
            
            if (next >= quantity) {
                inflate(inflateSize);
            }

            storage[next++] = element;
            
            return(next - 1); // Index number
        }

        ~PStash() {
            delete []storage;
        }

        void* operator[](int index) const {
            if(index >= next) {
                return 0;
            }

            return storage[index];
        }

        void* remove(int index) {
            void* v = operator[](index);

            if (v != 0) {
                storage[index] = 0;
            }

            return v;
        }

        void inflate(int increase) {
            const int size = sizeof(void*);
            void** temp = new void*[quantity + increase];

            memset(temp, 0, (quantity + increase) * size);
            memcpy(temp, storage, quantity * size);
            
            quantity += increase;
            delete []storage;
            
            storage = temp;
        } 
};
#endif // PSTASH_H


