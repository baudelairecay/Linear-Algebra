#include "../matrix.hpp"
using namespace std;
// Because of the nature of these operations, subtract and scalar multiplication will be tested here as well

void visualTestScalarMul(Matrix A, float scalar){
    Matrix lambdaA = scalarMul(A,scalar);
    lambdaA.print();
}

void testScalarMul(vector<vector<float>> expected, float scalar, Matrix mat){
    Matrix lambdaA = scalarMul(mat, scalar);
    if(lambdaA.getElements() == expected){
        cout << "All is well" << endl;
    }else{
        throw runtime_error("Output does not equal expected");
    }
    
}

void visualTestAdd(Matrix A, Matrix B){
    Matrix AplusB = add(A,B);
    AplusB.print();
}

void testAdd(Matrix A, Matrix B, vector<vector<float>> expected){
    Matrix AplusB = add(A,B);
    if(AplusB.getElements() == expected){
        cout << "All is well" << endl;
    }else{
        throw runtime_error("Output does not equal expected");
    }
}

void visualTestSub(Matrix A, Matrix B){
    Matrix AminusB = sub(A,B);
    AminusB.print();
}

void testSub(Matrix A, Matrix B, vector<vector<float>> expected){
    Matrix AminusB = sub(A,B);
    if(AminusB.getElements() == expected){
        cout << "All is well" << endl;
    }else{
        throw runtime_error("Output does not equal expected");
    }
}

int main(void){
    vector<vector<float>> a = {{1,2}, {1,3}};
    vector<vector<float>> b = {{1,2}, {3,4}};
    vector<vector<float>> expectedAdd = {{2,4}, {4,7}};
    vector<vector<float>> expectedSub = {{0,0}, {-2, -1}};
    vector<vector<float>> expectedScalarMul = {{4,8}, {12,16}};
    Matrix A = Matrix(a);
    Matrix B = Matrix(b);
    float scalar = 4;

    cout << "Testing Scalar Multiplication(square Matrix):" << endl;
    visualTestScalarMul(B, scalar);
    testScalarMul(expectedScalarMul, scalar, B);

    cout << "Testing Scalar Multiplication(m x n matrix, where m < n):" << endl;
    b = {{1,2,3}, {1,2,3}};
    B = Matrix(b);
    expectedScalarMul = {{4,8,12}, {4,8,12}};
    visualTestScalarMul(B, scalar);
    testScalarMul(expectedScalarMul, scalar, B);

    cout << "Testing Scalar Multiplication(m x n matrix, where m > n):" << endl;
    b = {{1,2}, {1,2}, {1,2}};
    B = Matrix(b);
    expectedScalarMul = {{4,8}, {4,8}, {4,8}};
    visualTestScalarMul(B, scalar);
    testScalarMul(expectedScalarMul, scalar, B);

    cout << "Testing matrix add/substract (square matrices):" << endl;
    a = {{1,2}, {1,3}};
    b = {{1,2}, {3,4}};
    A = Matrix(a);
    B = Matrix(b);
    expectedAdd = {{2,4}, {4,7}};
    expectedSub = {{0,0}, {-2, -1}};
    cout << "Result from addition:" << endl;
    visualTestAdd(A,B);
    testAdd(A,B,expectedAdd);
    cout << "Result from substraction:" << endl;
    visualTestSub(A,B);
    testSub(A,B,expectedSub);

    cout << "Testing matrix add/substract (m x n matrix, where m < n):" << endl;
    a = {{1,2,3}, {1,2,3}};
    b = {{1,2,3}, {2,3,4}};
    A = Matrix(a);
    B = Matrix(b);
    expectedAdd = {{2,4,6}, {3,5,7}};
    expectedSub = {{0,0,0}, {-1,-1,-1}};
    cout << "Result from addition:" << endl;
    visualTestAdd(A,B);
    testAdd(A,B,expectedAdd);
    cout << "Result from substraction:" << endl;
    visualTestSub(A,B);
    testSub(A,B,expectedSub);

    cout << "Testing matrix add/substract (m x n matrix, where m < n):" << endl;
    a = {{1,2}, {3,4}, {5,6}};
    b = {{7,8}, {2,3}, {9,10}};
    A = Matrix(a);
    B = Matrix(b);
    expectedAdd = {{8,10}, {5,7}, {14,16}};
    expectedSub = {{-6,-6}, {1,1}, {-4,-4}};
    cout << "Result from addition:" << endl;
    visualTestAdd(A,B);
    testAdd(A,B,expectedAdd);
    cout << "Result from substraction:" << endl;
    visualTestSub(A,B);
    testSub(A,B,expectedSub);
    
    cout << "Testing matrices of different sizes:" << endl;
    a = {{1,2,3}, {1,3,4}};
    b = {{1,2}, {3,4}}; 
    A = Matrix(a);
    B = Matrix(b);
    add(A,B);
    

    return 0;
}