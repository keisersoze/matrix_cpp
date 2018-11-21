//
// Created by Filippo Maganza on 12/11/2018.
//

#include <iostream>
#include <memory>
#include "base_matrix.h"

int main (){
    /*int  mymatrix [3][3] = { { 1, 2, 3 },
                             { 4, 5, 6 },
                             { 7, 8, 9 } };*/
    std::array< int , 6> a2 = {1, 2, 3, 4, 5, 6};
    base_matrix<int,2,3> matrix1(a2);
    //matrix1.print();
    cout<<matrix1(1,3)<<" ";
    transposed_matrix<int,3,2> transposed1 = matrix1.transpose(); // se non vuoi che sia possibile creare una transposed_matrix basta scrivere private o protected nella classe.
    cout<<transposed1 (3,1)<<"\n";
    cout << matrix1.submatrix(1,2,2,3).at(2,2) << "\n";

    return 0;
}
