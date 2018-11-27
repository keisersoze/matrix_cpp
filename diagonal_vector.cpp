//
// Created by Arnaldo Santoro.
//
#include <iostream>
#include <memory>
#include "matrix.h"
#include <string>

//Utility function that prints Rows and Columns of a matrix.


int main (){
    try{
        std::vector < float > a1 = {0.1,0.2,0.3,0.4,0.5,0.6};
    matrix <float> double_matrix (a1,3,2);
    
    auto double_diagonal_vector =double_matrix.diagonal();
    
    cout<<prettyprint(double_diagonal_vector)<<"double diagonal vector iterator doesn't go out of bound;\n\n";

    print_row_col(double_diagonal_vector);

    cout<<"\nit works even if it's transposed.\n"<<prettyprint(double_diagonal_vector.transpose());

        print_row_col(double_diagonal_vector.transpose());


    } catch(char const* matrix_error ){
    cerr<<endl<<matrix_error<<endl;

    };

return 0;
}
