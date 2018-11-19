//
// Created by Filippo Maganza on 12/11/2018.
//

#include <iostream>
#include <memory>
#include "Matrix.h"



int main (){
    /*int  mymatrix [3][3] = { { 1, 2, 3 },
                             { 4, 5, 6 },
                             { 7, 8, 9 } };*/
    std::array< int , 4> a2 = {1, 2, 3, 4};
    std::array< int , 3> a3 = {1, 2, 3};
    Matrix<int,2,2> matrix(a2);
    matrix.print();
    cout<<matrix(2,2);
    return 0;
}
