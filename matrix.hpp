#include <iostream>
#include <vector>
using namespace std;
class Matrix{
    unsigned int rows, columns;
    vector<vector<int>> elements = {};
    public:
        Matrix(int numberOfRows, int numberOfCols);
        Matrix(vector<vector<int>> vec); 
        int getNumberOfRows();
        int getNumberOfColumns();
        vector<vector<int>> getElements();
        int size(); 
        void fill(int data, int numberOfRows, int numberOfColumns);
        void print();
};
Matrix add(Matrix A, Matrix B);
Matrix sub(Matrix A, Matrix B);
Matrix multiply(Matrix A, Matrix B);
Matrix transpose(Matrix mat);