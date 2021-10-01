#ifndef HANDLE_H
#define HANDLE_H

class Handle {
    struct Cheshire;
    Cheshire* smile;
    
    public:
        void initialize(); // constructor
        void cleanup(); // destructor
        int read(); // constructor
        void change(int);
        void printOut();

        void setValue(); // constructor
        void resetValue(); // destructor
};
#endif