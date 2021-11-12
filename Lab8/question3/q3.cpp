/*
Templatize the IntArratclass in IostreamOperatorOverloading.cpp from Chapter 12, templatizing both the type of object that is contained and the
size of the internal array.
*/

#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstddef>

using namespace std;

template<typename T, size_t size>
class Ar{

    T a[size];
    
    public:
        Ar() {memset(a, 0, size*sizeof(*a));}
        
        T& operator[](int b){
            assert(b >= 0 && b < size);
            
            return a[b];
        }

        //inline member template 
        friend ostream& //output stream of objects
        
        operator << (ostream& io, const Ar <T, size>& ii){
            for (int i = 0; i < size; i++){
                io << ii.a[i];
                
                if (i != (size - 1)) {
                    io << ", ";
                }
            }

            io << endl;
            
            return io;
        }

        friend istream& //input stream objects 

        operator >> (istream& is, Ar <T, size>& aa){
            for(int i = 0; i < size; i++) {
                is >> aa.a[i];
            }

            return is;
        }

        //out-of line template
        #if 0
        friend ostream&
        operator << (ostream& io, const Ar <T, size>& ii);
        friend istream&
        operator >> (istream& is, Ar <T, size>& aa);
        #endif
};

#if 0

template<typename T, size_t size>
ostream&
operator << (ostream& io, const Ar <T, size>* ii){
    for (int i = 0; i < N; i++){
        io << ii.a[i];
        if(i != (size - 1)) {
            io << ", ";
        }
    }

    io << endl;
    return io;
}

template<typename T, size_t size>
operator >>(istream& is, Ar <T, size>& aa){
    for(int i = 0; i < size; i++)
        is >> aa.a[i];
    return is;
}

#endif

int main() {

    stringstream input("41 65 1324 654 234 54 65");
    
    Ar<int, 7> I;
    
    input >> I;
    
    I[6] = -1;
    
    cout << I;
}