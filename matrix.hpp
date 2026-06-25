#include <vector>
using namespace std;
class Matrix{
    unsigned int rows, columns;
    vector<vector<int>> elements = {};
    public:
        Matrix(int numberOfRows, int numberOfCols);
        Matrix(vector<vector<int>> vec); 
        void add(int data, int row, int col);
        int size(); 
        void transpose();
        void print();
};