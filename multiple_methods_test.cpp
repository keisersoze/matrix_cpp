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
    std::vector < int > a2 = {1,2,3,4,5,6};
    matrix<int> int_matrix(a2,2,3);
    
    auto int_diagonal_matrix = int_matrix.diagonal_matrix();
    auto int_diagonal_vector = int_matrix.diagonal();
    auto int_submatrix = int_matrix.submatrix( 1,1,2,2);
    const auto chain_methods_matrix = int_matrix.transpose().submatrix(1,1,2,2).diagonal_matrix().diagonal();

    cout<<"first matrix\n"<<prettyprint(int_matrix)<<"\n";
    cout<<"first matrix transposed\n"<<prettyprint(int_matrix.transpose())<<"\n";
    cout<<"first matrix diagonal vector"<<prettyprint(int_diagonal_vector)<<"\n";
    cout<<"first matrix diagonal matrix"<<prettyprint(int_diagonal_matrix)<<"\n";
    cout<<"submatrix"<<prettyprint(int_submatrix)<<"\n";

    cout<<"\nchain of methods 'transpose diagonal submatrix':\n"<<prettyprint(int_matrix.transpose().diagonal().submatrix( pair<int,int>(1,1),pair<int,int>(2,1) ))<<"\n";    
    cout<<"\nchain of methods 'tranpose submatrix diagonal_matrix diagonal':\n"<<prettyprint(chain_methods_matrix);


    } catch(char const* matrix_error ){
    cerr<<endl<<matrix_error<<endl;

    };

return 0;
}
