#include "../matrix.hpp"
using namespace std;

void visualTestTranpose(Matrix mat){
    mat.print();
    Matrix transposed = transpose(mat);
    cout << "transpose of matrix:" << endl;
    transposed.print();
}

void testTranspsoe(Matrix mat, vector<vector<float>> expected){
    Matrix transposed = transpose(mat);
    if(transposed.getElements() == expected){
        cout << "all is well" << endl;
    }else{
        throw runtime_error("Output does not equal output");
    }
}
int main(void){
    vector<vector<float>> vec = {{1,1}, {1,1}};
    vector<vector<float>> expected = {{1,1}, {1,1}};
    Matrix mat = Matrix(vec);

    cout << "square matrix test:" << endl; 
    visualTestTranpose(mat);
    testTranspsoe(mat, expected);

    cout << "more columns than rows test:" << endl; 
    vec = {{1,2,3}, {5,4,7}};
    expected = {{1,5}, {2,4}, {3,7}};
    mat = Matrix(vec);
    visualTestTranpose(mat);
    testTranspsoe(mat, expected);

    cout << "more rows than columns test:" << endl; 
    vec = {{0,7}, {9,5}, {3,4}};
    expected = {{0,9,3}, {7,5,4}};
    mat = Matrix(vec);
    visualTestTranpose(mat);
    testTranspsoe(mat, expected);

    cout << "empty matrix test:" << endl;
    vec = {};
    expected = {};
    mat = Matrix(vec);
    visualTestTranpose(mat);
    testTranspsoe(mat,expected);
    return 0;

}