//
// Created by Filippo Maganza on 12/11/2018.
//

#include <iostream>
#include "Matrix.h"

int main (){
    int  mymatrix [3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    Matrix<int, 3, 3> matrix(mymatrix);
    matrix.print();
    return 0;
}
