#include "../matrix.hpp"
using namespace std;

void visualTestFill(Matrix mat, float data, int numberOfRows, int numberOfColumns){
    mat.fill(data, numberOfRows, numberOfColumns);
    mat.print();
}

void testFill(Matrix mat, vector<vector<float>> expected, float data, int numberOfRows, int numberOfColumns){
    mat.fill(data, numberOfRows, numberOfColumns);
    if(mat.getElements() == expected){
        cout << "All is well" << endl;
    }else{
        throw runtime_error("Output does not equal expected");
    }
}

int main(void){
    vector<vector<float>> els = {{1,2,3}, {4,5,6}, {7,8,9}};
    Matrix mat = Matrix(els); 
    
    cout << "testing fill and resize up:" << endl;
    vector<vector<float>> expected = {{1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}};
    visualTestFill(mat, 1,4,4);  
    testFill(mat, expected,1,4,4);

    cout << "testing fill and resize down:" << endl;
    expected = {{1,1}, {1,1}};
    visualTestFill(mat,1,2,2);
    testFill(mat, expected,1,2,2);

    cout << "testing fill, no resize:" << endl;
    expected = {{1,1,1}, {1,1,1}, {1,1,1}};
    visualTestFill(mat,1,3,3);
    testFill(mat, expected, 1,3,3);

    cout << "testing fill, resize to non-square matrix(more columns):" << endl;
    expected = {{1,1,1}, {1,1,1}};
    visualTestFill(mat,1,2,3);
    testFill(mat,expected, 1,2,3);

    cout << "testing fill, resize to non-square matrix(more rows):" << endl;
    expected = {{1,1}, {1,1}, {1,1}};
    visualTestFill(mat,1,3,2);
    testFill(mat,expected, 1,3,2);

    cout << "Tesing what happens when you want to resize the array down to 0 rows, and 0 columns" << endl;
    expected = {};
    visualTestFill(mat, 0, 0, 0);
    testFill(mat,expected, 0, 0, 0);
    cout << mat.size() << endl;

    cout << "Testing what happens when expected size, is different than the give number of rows and/or columns" << endl;
    expected = {{1,1}, {1,1}, {1,1}};
    visualTestFill(mat,1,3,3);
    testFill(mat,expected, 1,3,3);

    return 0;
}