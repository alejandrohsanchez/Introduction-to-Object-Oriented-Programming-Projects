/*
Create a Matrix class which is made from a vector<vector<int> >. Provide it with a
friend ostream& operator<<(ostream&, const Matrix&) to display the matrix. Create the following using the STL
algorithms where possible (you may need to look up the mathematical meanings of the matrix operations if you
don’t remember them): operator+(const Matrix&, const Matrix&) for Matrix addition, operator*(const Matrix&,
const vector<int>&) for multiplying a matrix by a vector, and operator*(const Matrix&, const Matrix&) for matrix
multiplication. Demonstrate each. [45 pts]
*/

#include <iostream>
#include <vector>

using namespace std;

class Matrix{
        vector<vector<int> >Mat;
        int m, n;
    public:
        Matrix(int n, int m){
            this->m = m;
            this->n = n;
            this->Mat.resize(n);
            for(auto &a:this->Mat){
                a.resize(m);
            }
        }
        Matrix():Matrix(0,0){}
        ~Matrix(){
            this->m=0;
            this->n=0;
            this->Mat.clear();
        }
        friend ostream &operator<<(ostream &out, const Matrix &Mat);
        friend istream &operator>>(istream &in, Matrix &Matr);
        friend Matrix operator+(const Matrix &lhs, const Matrix &rhs);
        friend Matrix operator*(const Matrix &lhs, const Matrix &rhs);
        friend Matrix operator*(const Matrix &lhs, const vector<int> &rhs);
};

//display output with overloaded stream insertion
ostream &operator<<(ostream &out, const Matrix &Matr){
    for(int i=0; i<Matr.n; i++){
        for(int j=0; j<Matr.m; j++){
            out<<Matr.Mat[i][j]<<" ";
        }
        out<<"\n";
    }
    return out;
}

//input from console through overloaded stream extraction
istream &operator>>(istream &in, Matrix &Matr){
    cout<<"Enter numbers in Matrix with "<<Matr.m<<" rows and "<<Matr.n<<" columns\n";
    for(int i=0; i<Matr.n; i++){
        for(int j=0; j<Matr.m; j++){
            in>>Matr.Mat[i][j];
        }
    }
    return in;
}

//Matrix addition on two matrices
Matrix operator+(const Matrix &lhs, const Matrix &rhs){
    //result generated if rows and columns of both matrices match
    if(lhs.m==rhs.m && lhs.n==rhs.n){
        Matrix re(lhs.n,lhs.m);
        for(int i=0; i<lhs.n; i++){
            for(int j=0; j<lhs.m; j++){
                re.Mat[i][j]=lhs.Mat[i][j]+rhs.Mat[i][j];
            }
        }
        return re;
    }
    else{
        Matrix re;
        cout<<"Row columns not matching. Empty Matrix."<<endl;
        return re;
    }
}

//Matrix multiplication
Matrix operator*(const Matrix &lhs, const Matrix &rhs){
    //multiplication can only occur if column of first matrix equals the rows of second matrix
    if(lhs.m==rhs.n){
        Matrix re(lhs.n,rhs.m);
        for(int i=0; i<lhs.n; i++){
            for(int j=0; j<rhs.m; j++){
                for(int k =0; k<rhs.n; k++){
                    re.Mat[i][j]+=lhs.Mat[i][k]*rhs.Mat[k][j];
                }
            }
        }
        return re;
    }
    else{
        Matrix re;
        cout<<"Row column not matching. Empty Matrix."<<endl;
        return re;
    }
}

Matrix operator*(const Matrix &lhs, const vector<int>&rhs){
    if(lhs.m==rhs.size()){
        Matrix re=lhs;
        for(auto &a:re.Mat){
            for(int i=0; i<rhs.size(); i++){
                a[i]*=rhs[i];
            }
        }
        return re;
    }
    else{
        Matrix re;
        cout<<"Row mismatched with vector size. Empty Matrix."<<endl;
        return re;
    }
}

int main(){
    Matrix mAdd(2,3);
    Matrix mVec(2,3);
    Matrix mMult(3,2);
    cin>>mAdd;
    cin>>mVec;
    cin>>mMult;
    Matrix re1=mAdd+mVec;
    cout<<re1;
    Matrix re2=mVec+mMult;
    cout<<re2;
    Matrix re3=mAdd*mMult;
    cout<<re3;
    Matrix re4=mAdd*mVec;
    cout<<re4;
    vector<int>v1={1,2,3};
    Matrix re5=mAdd*v1;
    cout<<re5;
    return 0;
}