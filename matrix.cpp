#include "matrix.hpp"
using namespace std;

Matrix::Matrix(int numberOfRows, int numberOfCols){
    rows = numberOfRows;
    columns = numberOfCols;
    elements.resize(numberOfRows, vector<int>(numberOfCols,0));
}
Matrix::Matrix(vector<vector<int>> vec){
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

vector<vector<int>> Matrix::getElements(){
    vector<vector<int>> copy = elements;
    return copy;
}

void Matrix::add(int data, int row, int col){
    if(row >= rows || col >= columns){
        throw out_of_range("Error: attempt to add element out of bounds");
    }else if(elements[row][col] != 0){
        cerr << "Warning: an element has already been stored here" << endl;
    }
    elements[row][col] = data;
}

int Matrix::size(){
    return (rows*columns);
}

void Matrix::fill(int data, int numberOfRows, int numberOfColumns){
    vector<vector<int>> tmp(numberOfRows, vector<int>(numberOfColumns, data));
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

Matrix transpose(Matrix mat){
    int rows = mat.getNumberOfRows();
    int columns = mat.getNumberOfColumns();
    vector<vector<int>> transposed(columns, vector<int>(rows));
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < columns; j++){
            transposed[j][i] = mat.getElements()[i][j];
        }
    }
    return Matrix(transposed);
}