#include "../matrix.hpp"


int main(void){
    vector<vector<float>> els = {};
    // Test empty matrix
    Matrix mat = Matrix(els); // should throw a runtime error
    return 0;
}