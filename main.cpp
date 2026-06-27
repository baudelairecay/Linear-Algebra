#include <iostream>
#include "matrix.hpp"
using namespace std;


int main(void){
    vector<vector<float>> vec = {{1,2,3}, {4,5,6}, {7,8,9}};
    Matrix mat(vec);
    mat.fill(0.007, 10, 10);
    mat.print();
}