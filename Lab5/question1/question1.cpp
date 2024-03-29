/*
Modify Instrument3.cpp by adding a virtual prepare()
function. Call prepare() inside tune().
*/

#include <iostream>
using namespace std;
enum note { middleC, Csharp, Cflat }; // Etc.

class Instrument {
    public:
        virtual void play(note) const {
            cout << "Instrument::play" << endl;
        }
        
        /* prepare function declaration */
        virtual void prepare() const {
            cout << "Instrument::prepare" << endl;
        }
};

class Wind : public Instrument {
    public:
        /* prepare() definition from Wind class member */
        void prepare() const {
            cout << "Wind::prepare" << endl;
        }
        
        void play(note) const {
            cout << "Wind::play" << endl;
        }
};

void tune(Instrument& i) {
    /* Calling prepare() from inside tune() */
    i.prepare();
    i.play(middleC);
}


int main() {
    Wind flute;
    tune(flute); // Upcasting
}