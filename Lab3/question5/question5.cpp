#include <iostream>
#include <vector>
#include <string>

using namespace std;

class StringVector : public vector<void*> {
    public:
        StringVector() : vs() {}
        void push_back(string *s) {
            vs.push_back(s);
        }
        string *operator[] (size_t index) {
            return vs[index];
        }
    private:
        vector<string*> vs;
};


int main() {
    StringVector v;
    string str = "test";
    void *vPtr = static_cast<void*>(&str);
    
    return 1;
}