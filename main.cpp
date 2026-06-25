#include <iostream>
#include "matrix.hpp"
using namespace std;

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

//void Matrix::transpose(){}

void Matrix::print(){
    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows; j++){
            cout << elements[i][j] << " ";
            }
        cout<<endl;
    }
}


int main(void){
    vector<vector<int>> vec = {{1,2,3}, {4,5,6}, {7,8,9}};
    Matrix mat(vec);
    mat.print();
    mat.add(5,0,0);
    mat.print();
    return 0;
}