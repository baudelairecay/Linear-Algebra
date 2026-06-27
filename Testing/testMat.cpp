#include "../matrix.hpp"


int main(void){
    vector<vector<int>> els;
    // Test empty matrix
    // Matrix mat = Matrix({}); // should throw a runtime error
    // Matrix mat1 = Matrix(els); // should throw a runtime error
    Matrix mat3 = Matrix(0,0); // this is an interesting case, that I'll tend to later
    // Proposed solution: allow its creation but prevent the use of any of our operations, it simply exists as a placeholder.
    // each case successfully throws a runtime error
    return 0;
}