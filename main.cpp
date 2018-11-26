//
// Filippo Maganza and Arnaldo Santoro
//

#include <iostream>
#include <memory>
#include "matrix.h"
#include <string>


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
//    m4(1,0)=16;

    
    cout<<prettyprint(int_matrix)<<"first matrix\n\n";
    cout<<"double diagonal matrix column number is "<< double_diagonal_matrix.getColumnNumber()<<endl<<endl;
    cout<<prettyprint(double_matrix)<<"double matrix\n\n";
    cout<<prettyprint(double_diagonal_matrix)<<"double diagonal matrix \n\n";
    cout<<prettyprint(double_diagonal_vector)<<"double diagonal vector \n\n"; //iterator goes out of bound
    cout<<prettyprint(diagonal_int_vector)<<"diagonal vector\n\n";
    cout<<prettyprint(transposed_int_submatrix)<<"transposed submatrix\n\n";
    transposed_int_submatrix(1,1) = 666;
    cout<<prettyprint(int_matrix)<<"first matrix modified\n\n";
    cout<<prettyprint(copy_int_matrix)<<"copied matrix\n\n";
    cout<<prettyprint(int_submatrix)<<"submatrix\n\n";
    cout<<prettyprint(int_submatrix2)<<"other submatrix\n\n";
    cout<<prettyprint(int_diagonal_matrix)<<"diagonal matrix\n\n";
    /*for (auto i = m1.begin(); i != m1.end() ; ++i) {
        cout<< *i;
    }*/
}catch(char const* matrix_error ){
    cerr<<endl<<matrix_error<<endl;
};

return 0;
}
