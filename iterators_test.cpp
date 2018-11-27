//
// Created by Filippo Maganza
//
#include <iostream>
#include <memory>
#include "matrix.h"
#include <string>
#include <sstream>

int main (){

    std::vector < int > a2 = {1,2,3,4,5,6};
    matrix<int> int_matrix(a2,2,3);

    auto m1 = int_matrix.transpose().submatrix(pair<int,int>(1,1),pair<int,int>(2,2));

    auto m2 = m1;

    vector < int > v;
    for (auto i = m2.begin(); i != m2.end() ; ++i) {
        v.push_back(*i);
    }

    v.push_back(0);
    
    for (auto i = m2.begin_column(); i != m2.end_column() ; ++i) {
        v.push_back(*i);
    }

    std::stringstream ss;
    for(size_t i = 0; i < v.size(); ++i)
    {
        if(i != 0)
            ss << ",";
        ss << v[i];
    }
    cout << ss.str();

    return 0;
}