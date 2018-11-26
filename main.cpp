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
    std::vector < float > a1 = {0.1,0.2,0.3,0.4,0.5,0.6};
    matrix <float> mf (a1,3,2);
    auto mf2 =mf.diagonal_matrix();
    cout<< prettyprint(mf2);
    matrix<int> m(a2,2,3);
    matrix<int> m_=m;
    auto m1 = m.transpose().submatrix(pair <int, int> (2,1), pair <int, int> (3,2));
    auto m2 = m.diagonal();
    auto m3 = m.submatrix(pair<int, int> (1,1),pair<int, int>(2,2));
    auto m4 = m.diagonal_matrix();
    m4(1,1)=16;

    m2(2,1) = 10;
    cout<<prettyprint(m);
    cout<<prettyprint(m_);
    cout<<prettyprint(m1);
    cout<<prettyprint(m2);
    cout<<prettyprint(m3);

    /*for (auto i = m1.begin(); i != m1.end() ; ++i) {
        cout<< *i;
    }*/
}catch(char const* matrix_error ){
    cerr<<endl<<matrix_error<<endl;
};

return 0;
}
