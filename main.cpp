//
// Created by Filippo Maganza on 12/11/2018.
//

#include <iostream>
#include <memory>
#include "matrix.h"


int main (){
    /*int  mymatrix [3][3] = { { 1, 2, 3 },
                             { 4, 5, 6 },
                             { 7, 8, 9 } };*/
    std::vector < int > a2 = {1, 2, 3, 4, 5, 6};
    matrix<int> matrix1(a2,2,3);
    cout<<matrix1.get(2,3);

    return 0;
}
