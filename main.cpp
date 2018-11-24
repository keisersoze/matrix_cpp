//
// Filippo Maganza and Arnaldo xxx
//

#include <iostream>
#include <memory>
#include "matrix.h"
#include <string>


int main (){
    /*int  mymatrix [3][3] = { { 1, 2, 3 },
                             { 4, 5, 6 },
                             { 7, 8, 9 } };*/
    std::vector < int > a2 = {1,2,3,4,5,6};
    matrix<int> m(a2,2,3);
    matrix<int> m1 = m.transpose();
    matrix<int> m2 = m.diagonal();

    cout<<m1.get(1,2);
    cout<<m2.get(2,3);
    
    return 0;
}
