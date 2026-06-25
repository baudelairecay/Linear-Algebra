#include <iostream>
#include <vector>
using namespace std;
class Matrix{
    unsigned short rows, columns;
    vector<vector<int>> elements = {};
    public:
        Matrix(int numberOfRows, int numberOfCols){
            rows = numberOfRows;
            columns = numberOfCols;
            elements.resize(numberOfRows, vector<int>(numberOfCols, 0));
        }
        Matrix(vector<vector<int>> vec){
            elements = vec;
            rows = vec[0].size();
            columns = vec.size();
        }
        void add(int data, int row, int col){
            if(row > rows || col > columns){
                throw runtime_error("Error: attempt to add element out of bounds");
            }
            elements[row][col] = data;
        }
        int size(){
            return (rows*columns);
        }
        void printMat(){
            for(int i = 0; i < columns; i++){
                for(int j = 0; j < rows; j++){
                    cout << elements[i][j] << " ";
                }
                cout<<endl;
            }
        }
};


int main(void){
    vector<vector<int>> vec = {{1,2,3}, {4,5,6}, {7,8,9}};
    Matrix mat(vec);
    mat.add(6,9,0);
    return 0;
}