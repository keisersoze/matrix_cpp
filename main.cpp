//
// Filippo Maganza and Arnaldo xxx
//

#include <iostream>
#include <memory>
#include "matrix.h"
#include <string>


int main (){
try{
    /*int  mymatrix [3][3] = { { 1, 2, 3 },
                             { 4, 5, 6 },
                             { 7, 8, 9 } };*/
    std::vector < int > a2 = {1,2,3,4,5,6};
    matrix<int> m(a2,2,3);
    matrix<int> m1 = m.transpose().submatrix(pair <int, int> (2,1), pair <int, int> (3,2));
    matrix<int> m2 = m.diagonal();
    matrix<int> m3 = m.submatrix(pair<int, int> (1,1),pair<int, int>(2,2));

    cout<<prettyprint(m1);
    cout<<m1.get(1,2);
    cout<<m2.get(2,1);
//    cout<<m2(2,1);
//    non funzia :(
}catch(char const* matrix_error ){
    cerr<<endl<<matrix_error<<endl;
};

return 0;
}
