#include <iostream>
#include "matrix.hpp"
using namespace std;


int main(void){
    vector<vector<int>> vec = {{1,2,3}, {4,5,6}, {7,8,9}};
    Matrix mat(vec);
    cout << "Matrix before transpose:" << endl;
    cout << "rows: " << mat.getNumberOfRows() << " columns: " << mat.getNumberOfColumns() << endl;
    mat.print();
    Matrix transposed = transpose(mat);
    cout << "Matrix after transpose:" << endl;
    cout << "rows: " << transposed.getNumberOfRows() << " columns: " << transposed.getNumberOfColumns() << endl;
    transposed.print();
    return 0;
}