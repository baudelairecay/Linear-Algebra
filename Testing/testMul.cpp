#include "matrix.cpp"

void visualTestMul(Matrix A, Matrix B){

}

void testMul(Matrix A, Matrix B, vector<vector<float>> expected){

}

int main(void){
    vector<vector<float>> a = {{4,2}, {3,4}};
    vector<vector<float>> b = {{2,3}, {1,4}};
    Matrix A = Matrix(a);
    Matrix B = Matrix(b);
    Matrix C =  mul(A,B);
    C.print();
    return 0;
}