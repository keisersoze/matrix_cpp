//
// Filippo Maganza and Arnaldo Santoro
//

#include <iostream>
#include <memory>
#include "matrix.h"
#include <string>
template <typename E>
void print_row_col(const matrix<E>& matrix){
    cout<<"this matrix's row and column numbers are "<<matrix.getRowNumber()<<" and "<<matrix.getColumnNumber()<<endl<<endl;
}

int main (){
try{


    std::vector < int > a2 = {1,2,3,4,5,6};
    std::vector < float > a1 = {0.1,0.2,0.3,0.4,0.5,0.6};
    matrix <float> double_matrix (a1,3,2);
    auto double_diagonal_matrix =double_matrix.diagonal_matrix();
    auto double_diagonal_vector =double_matrix.diagonal();
    matrix<int> int_matrix(a2,2,3);
    matrix<int> copy_int_matrix = int_matrix;
    auto transposed_int_submatrix = int_matrix.transpose().submatrix(pair <int, int> (2,1), pair <int, int> (3,2));
    auto diagonal_int_vector = int_matrix.diagonal();
    pair<int,int> onePair {1,1}, twoPair{2,1};
    auto int_submatrix = int_matrix.submatrix(onePair, twoPair);
    auto int_submatrix2 = int_matrix.submatrix(pair<int, int> (1,1),pair<int, int>(2,2));
    auto int_diagonal_matrix = int_matrix.diagonal_matrix();
    
    //      **PRINTS OF DECLARED MATRICES**            //
    //A matrix is printed with a subtitled explaination//

    cout<<prettyprint(int_matrix)<<"first matrix\n\n";

    cout<<prettyprint(int_matrix.transpose())<<"first matrix transposed\n\n";

    cout<<prettyprint(double_matrix)<<"double matrix\n\n";
    
    cout<<prettyprint(double_diagonal_matrix)<<"double diagonal matrix \n\n";
    
    //A double diagonal vector modifies the column and row number, adjusting it to proper size.

    cout<<prettyprint(double_diagonal_vector)<<"double diagonal vector iterator doesn't go out of bound;\n\n";

    print_row_col(double_diagonal_matrix);

    cout<<prettyprint(double_diagonal_vector.transpose())<<"even if it's transposed.\n\n";
    
    cout<<prettyprint(diagonal_int_vector)<<"Another diagonal vector.\n\n";
    
    cout<<prettyprint(transposed_int_submatrix)<<"transposed submatrix.\n\n";

    print_row_col(transposed_int_submatrix);

    cout<<prettyprint(transposed_int_submatrix.diagonal_matrix())<<"transposed diagonal submatrix.\n\n";
    
    //Modifying elements of a matrix doesn't affect copied matrices

    cout<<"\nModifying elements of a matrix doesn't affect copied matrices:\n";
    transposed_int_submatrix(1,1) = 666;

    cout<<prettyprint(int_matrix)<<"first matrix, after calling 'transposed_int_submatrix(1,1) = 666' \n\n";

    cout<<prettyprint(copy_int_matrix)<<"copied matrix isn't affected by the modification;\n\n";

    cout<<prettyprint(int_submatrix2)<<"but it's submatrix is.\n\nNow a series of copied matrices, with some operations:\n";

    //Testing types and eventually find errors

    cout<<prettyprint(int_diagonal_matrix)<<"diagonal matrix\n\n";

    matrix<int> copy_transposed_int_matrix = copy_int_matrix.transpose();

    cout<<"\n" << prettyprint(copy_transposed_int_matrix)<<"transposed copied matrix\n";

    auto copy_transposed_int_matrix2 = copy_int_matrix.transpose();

    cout<<"\n" << prettyprint(copy_transposed_int_matrix2)<<"transposed copied matrix with automatic type detection \n";

    auto copy_diagonal_int_matrix = copy_int_matrix.diagonal_matrix();

    cout<<"\n" << prettyprint(copy_diagonal_int_matrix)<<"diagonal copied matrix with auto\n";

    const auto copy_diagonal_int_matrix_X = copy_int_matrix.diagonal_matrix();

    cout<<"\n" << prettyprint(copy_diagonal_int_matrix_X)<<"diagonal copied matrix with 'const auto' type\n\n Those that follow are some 'const matrix' tests\n\n";
    
    int vediamoSeSalvaIlValore {int_matrix.diagonal_matrix()(2,2)};
    cout<<"Let's see if a value from a diagonal matrix is saved to an int: "<<vediamoSeSalvaIlValore<<"\n";

    cout<<"Ok, but what if I directly print the value without saving it to another variable? "<<int_matrix.diagonal_matrix()(2,2)<<"\n";

    const auto testMatrix = int_matrix.diagonal_matrix();

    cout<<"\nBut then also this should work: "<< testMatrix(2,2)<<"!\n";

    cout<<"Luckily that's just an exclamation mark, and not a factorial\nNow some gets from a double_matrix.diagonal_vector: ";
    cout<<"\n"<<double_diagonal_vector(1,1)<<"\n";

//    cout<<"\nSome gets:"<<double_diagonal_matrix(2,2)<<int_submatrix2(2,2)<<"\n"<<transposed_int_submatrix(1,2); // commented out code throws row out of bound error
//stesso errore di riga 68
    
cout<<"\nNow I'll make an incorrect get, using either higher or lower row or column than allowed";

cout<<"\nSome dyslexic gest:\n"<<int_matrix(1,1)<<"\n"<<int_matrix(2,2)<<"\n"<<double_diagonal_vector.transpose()(1,2);

} catch(char const* matrix_error ){
    cerr<<endl<<matrix_error<<endl;

};

return 0;
}
