#include <iostream>
#include <vector>
using namespace std;
class Matrix{
    unsigned int rows, columns;
    vector<vector<float>> elements = {};
    public:
        Matrix(vector<vector<float>> vec); 
        int getNumberOfRows();
        int getNumberOfColumns();
        vector<vector<float>> getElements();
        int size(); 
        void fill(float data, unsigned int numberOfRows, unsigned int numberOfColumns);
        void print();
};
Matrix add(Matrix A, Matrix B);
Matrix scalarMul(Matrix mat, float scalar);
Matrix sub(Matrix A, Matrix B);
Matrix mul(Matrix A, Matrix B);
Matrix transpose(Matrix mat);