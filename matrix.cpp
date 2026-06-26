#include "matrix.hpp"

Matrix::Matrix(int numberOfRows, int numberOfCols){
    rows = numberOfRows;
    columns = numberOfCols;
    elements.resize(numberOfRows, vector<int>(numberOfCols,0));
}
Matrix::Matrix(vector<vector<int>> vec){
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
        cerr<< "Warning: an element as already been stored here" << endl;
    }
    elements[row][col] = data;
}

int Matrix::size(){
    return (rows*columns);
}


void Matrix::transpose(){
    vector<vector<int>> transposed(columns, vector<int>(rows));
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            transposed[j][i] = elements[i][j];
        }
    }
    elements = transposed;
    int tmp = rows;
    rows = columns;
    columns = tmp;
}

void Matrix::print(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << elements[i][j] << " ";
            }
        cout<<endl;
    }
}