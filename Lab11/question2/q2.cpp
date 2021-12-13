/*
2. Fill a vector<double> with numbers representing angles in radians. using function object composition, take the sine of all the elements in your vector.
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<double> sine(vector<double>vec){
    vector<double>result;
    int i;

    for(i = 0; i < vec.size(); i++){
        result.push_back(sin(vec.at(i)));
    }

    return result;
}

int main(){
    vector<double>vec;

    vec.push_back(0);
    vec.push_back(45);
    vec.push_back(90);
    vec.push_back(135);
    vec.push_back(180);
    vec.push_back(225);
    vec.push_back(270);
    vec.push_back(315);
    vec.push_back(360);

    vector<double>result = sine(vec);
    for(int i = 0; i < result.size(); i++){
        cout << result.at(i) << endl;
    }

    return 0;
}