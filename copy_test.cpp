//
// Created by Filippo Maganza .
//
#include <iostream>
#include <memory>
#include "matrix.h"
#include <string>

int main (){

    std::vector < int > a2 = {1,2,3,4,5,6};
    matrix<int> int_matrix(a2,2,3);

    //deep copy
    matrix<int> copied_matrix = int_matrix;

    int_matrix(2,2)=0;

    auto m1 = int_matrix.transpose().submatrix(pair<int,int>(2,1),pair<int,int>(2,2));

    m1(1,1)= -1;

    auto m2 = m1;

    cout << prettyprint(m1);
    cout << prettyprint(m2);
    cout << prettyprint(copied_matrix);

    return 0;
}