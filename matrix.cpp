#include "matrix.hpp"
using namespace std;
Matrix::Matrix(vector<vector<float>> vec){
    if(vec.size() == 0){
        throw runtime_error("Attempt to initalize Matrix with empty vector");
    }
    elements = vec;
    rows = vec.size();
    columns = vec[0].size();
}

int Matrix::getNumberOfRows(){
    return rows;
}

int Matrix::getNumberOfColumns(){
    return columns;
}

vector<vector<float>> Matrix::getElements(){
    vector<vector<float>> copy = elements;
    return copy;
}

int Matrix::size(){
    return (rows*columns);
}

void Matrix::fill(float data, unsigned int numberOfRows, unsigned int numberOfColumns){
    if(numberOfRows <= 0 || numberOfColumns <= 0){
        throw runtime_error("this causes weird behaviour, so I won't allow it");
    }
    vector<vector<float>> tmp(numberOfRows, vector<float>(numberOfColumns, data));
    rows = numberOfRows;
    columns = numberOfColumns;
    elements = tmp;
}

void Matrix::print(){
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < columns; j++){
            cout << elements[i][j] << " ";
            }
        cout<<endl;
    }
}

Matrix add(Matrix A, Matrix B){
    vector<vector<float>> c = vector(A.getNumberOfRows(), vector<float>(A.getNumberOfColumns(), 0));
    vector<vector<float>> a = A.getElements();
    vector<vector<float>> b = B.getElements();
    if((A.getNumberOfRows() != B.getNumberOfRows()) || (A.getNumberOfColumns() != B.getNumberOfColumns())){
        throw runtime_error("Matrix addition is undefined for matrices of different sizes");
    }else{
        for(size_t i = 0; i < A.getNumberOfRows(); i++){
            for(size_t j = 0; j < A.getNumberOfColumns(); j++){
                c[i][j] += a[i][j] + b[i][j];
            }
        }
    }
    return Matrix(c);
}

Matrix scalarMul(Matrix mat, float scalar){
    vector<vector<float>> b = mat.getElements();
    for(size_t i = 0; i < mat.getNumberOfRows(); i++){
        for(size_t j = 0; j < mat.getNumberOfColumns(); j++){
            b[i][j] *= scalar;
        }
    }
    return Matrix(b);
} 

Matrix sub(Matrix A, Matrix B){
    Matrix negative_B = scalarMul(B, -1);
    return add(A, negative_B);
}

Matrix transpose(Matrix mat){
    int rows = mat.getNumberOfRows();
    int columns = mat.getNumberOfColumns();
    vector<vector<float>> transposed(columns, vector<float>(rows));
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < columns; j++){
            transposed[j][i] = mat.getElements()[i][j];
        }
    }
    return Matrix(transposed);
}