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
        void add(int data, int row, int col);
        int size(); 
        void fill(int data, int numberOfRows, int numberOfColumns);
        void print();
};
Matrix transpose(Matrix mat);