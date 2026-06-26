#include "../matrix.hpp"
using namespace std;

// I know this isn't the most efficient way to test, I'll write this later
void visualTestTranpose(Matrix mat){
    cout << "matrix:" << endl;
    mat.print();
    Matrix transposed = transpose(mat);
    cout << "transpose of matrix:" << endl;
    transposed.print();

}
int main(void){
    vector<vector<int>> vec1 = {{1,1}, {1,1}};
    vector<vector<int>> vec2 = {{1,1,1}, {1,1,1}};
    vector<vector<int>> vec3 = {{1,1}, {1,1}, {1,1}};
    Matrix mat1 = Matrix(vec1);
    Matrix mat2 = Matrix(vec2);
    Matrix mat3 = Matrix(vec3);

    cout << "square matrix test:" << endl; 
    visualTestTranpose(mat1);

    cout << "more columns than rows test:" << endl; 
    visualTestTranpose(mat2);

    cout << "more rows than columns test:" << endl; 
    visualTestTranpose(mat3);

    return 0;

}