//
// Created by Filippo Maganza on 12/11/2018.
//

#include <iostream>
#include <memory>
#include "matrix_impl.h"
#include "base_matrix.h"
#include "transposed_matrix.h"


int main (){
    /*int  mymatrix [3][3] = { { 1, 2, 3 },
                             { 4, 5, 6 },
                             { 7, 8, 9 } };*/
    std::array< int , 6> a2 = {1, 2, 3, 4, 5, 6};
    base_matrix<int,2,3> matrix1(a2);
    //matrix1.print();
    cout<<matrix1(1,3)<<" ";
    matrix1.transpose();
    return 0;
}
