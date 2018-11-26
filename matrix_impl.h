//
// Filippo Maganza and Aranldo Santoro
//

#include <vector>
#include <iostream>
#include <memory>

using namespace std;

/* UTILS FUNCTIONS */

template <typename E> E getZeroElement (){
    return nullptr;
}

template <> int getZeroElement <int> (){
    return 0;
}

template <> double getZeroElement <double> (){
    return 0.;
}

template <> float getZeroElement <float> (){
    return 0.;
}

template <> char getZeroElement <char> (){
    return '0';
}

template <> string getZeroElement <string> (){
    return "";
}

/* INTERFACE */

template < typename E>
class matrix_impl {

public:

    virtual E get(int accessed_row, int accessed_column) const = 0;

    virtual E& get_ref(int accessed_row, int accessed_column) = 0;

    virtual int getRowNumber() const = 0;

    virtual int getColumnNumber() const = 0;

    virtual ~matrix_impl() {};

};

/* BASE MATRIX */

template < typename E>
class base_matrix_impl : public matrix_impl <E>{

private:

    int r;
    int c;
    vector < E > data;
    
public:

    base_matrix_impl(const vector<E> &data, int r, int c) : r(r), c(c), data(data) {
        if (data.size() < r*c)
            throw ("Invalid input vector.");
        if (r < 1 || c < 1 ){
            throw ("Invalid matrix dimensions");
        }
    }

    int getRowNumber() const override {
        return r;
    }

    int getColumnNumber() const override {
        return c;
    }

    E get(int accessed_row, int accessed_column) const override {
        if (accessed_row < 1 || accessed_row > r) {
            throw "Out of bound row index";
        } else if (accessed_column < 1 || accessed_column > c) {
            throw "Out of bound column index";
        } else
            return data[c * (accessed_row - 1) + accessed_column - 1];
    }

    E &get_ref(int accessed_row, int accessed_column) override {
        if (accessed_row < 1 || accessed_row > r) {
            throw "Out of bound row index";
        } else if (accessed_column < 1 || accessed_column > c) {
            throw "Out of bound column index";
        } else{
            E& t= data.at(c * (accessed_row - 1) + accessed_column - 1);
            return t;
        }
    }

};

/* TRANSPOSED MATRIX */

template <typename E>
class transposed_matrix_impl : public matrix_impl <E>{

private:

    shared_ptr< matrix_impl<E> > matrix_ptr;

public:

    transposed_matrix_impl(shared_ptr < matrix_impl <E> > decorated_matrix_ptr):matrix_ptr(decorated_matrix_ptr){
    }

    int getRowNumber() const override {
        return matrix_ptr->getColumnNumber();
    }

    int getColumnNumber() const override {
        return matrix_ptr->getRowNumber();
    }

    E get(int accessed_row, int accessed_column) const override {
        if (accessed_row < 1 || accessed_row > getRowNumber()) {
            throw "Out of bound row index";
        } else if (accessed_column < 1 || accessed_column > getColumnNumber()) {
            throw "Out of bound column index";
        } else
            return matrix_ptr->get(accessed_column, accessed_row);
    }

    E &get_ref(int accessed_row, int accessed_column) override {
        if (accessed_row < 1 || accessed_row > getRowNumber()) {
            throw "Out of bound row index";
        } else if (accessed_column < 1 || accessed_column > getColumnNumber()) {
            throw "Out of bound column index";
        } else
            return matrix_ptr->get_ref(accessed_column, accessed_row);
    }

};


/* DIAGONAL MATRIX */

template <typename E>
class diagonal_impl : public matrix_impl <E>{

private:

    shared_ptr< matrix_impl<E> > matrix_ptr;

public:

    diagonal_impl(shared_ptr < matrix_impl <E> > decorated_matrix_ptr):matrix_ptr(decorated_matrix_ptr){
    }

    int getRowNumber() const override {
        return matrix_ptr->getRowNumber();
    }

  int getColumnNumber() const override {
      return 1;
    }

   E get(int accessed_row, int accessed_column) const override  {
        if (accessed_row < 1 || accessed_row > getRowNumber()) {
            throw "Out of bound row index";
        } else if (accessed_column != 1) {
            throw "Out of bound column index"; //TODO i messaggi vanno migliorati
        } else {
            return matrix_ptr->get(accessed_row, accessed_row);
        }
    }

    E &get_ref(int accessed_row, int accessed_column) override {
        if (accessed_row < 1 || accessed_row > getRowNumber()) {
            throw "Out of bound row index";
        } else if (accessed_column != 1) {
            throw "Out of bound column index"; //TODO i messaggi vanno migliorati
        } else {
            return matrix_ptr->get_ref(accessed_row, accessed_row);
        }
    }
};

/* SUBMATRIX MATRIX */

template <typename E>
class submatrix_matrix_impl : public matrix_impl <E>{

private:

    shared_ptr< matrix_impl<E> > matrix_ptr;

    int row_offset; //TODO unsigned
    int column_offset;
    int r;
    int c;
    
public:

   submatrix_matrix_impl(shared_ptr < matrix_impl <E> > decorated_matrix_ptr,
                         pair <int, int > first_pair, pair <int ,int > second_pair)
                         :matrix_ptr(decorated_matrix_ptr){
       if (first_pair.first < 1 || first_pair.second < 1 ||
           second_pair.first > matrix_ptr->getRowNumber() || second_pair.second > matrix_ptr->getColumnNumber() ||
           first_pair.first > second_pair.first || first_pair.second > second_pair.second){
           throw "Invalid submatrix input.";
       } else {
           row_offset = first_pair.first - 1;
           column_offset = first_pair.second - 1;
           r = second_pair.first - first_pair.first + 1;
           c = second_pair.second - first_pair.second + 1;
       }
    }

    int getRowNumber() const override {
        return r;
    }

    int getColumnNumber() const override {
        return c;
    }

    E get(int accessed_row, int accessed_column) const override {
        if (accessed_row < 1 || accessed_row > getRowNumber()) {
            throw "Out of bound row index";
        } else if (accessed_column < 1 || accessed_column > getColumnNumber()) {
            throw "Out of bound column index";
        } else {
            return matrix_ptr->get(accessed_row + row_offset, accessed_column + column_offset);
        }
    }

    E &get_ref(int accessed_row, int accessed_column) override {
        if (accessed_row < 1 || accessed_row > getRowNumber()) {
            throw "Out of bound row index";
        } else if (accessed_column < 1 || accessed_column > getColumnNumber()) {
            throw "Out of bound column index";
        } else {
            return matrix_ptr->get_ref(accessed_row + row_offset, accessed_column + column_offset);
        }
    }
};

// DIAGONAL MATRIX //

template <typename E>
class diagonal_matrix_impl : public matrix_impl <E>{

private:

    shared_ptr< matrix_impl<E> > matrix_ptr;

public:

    diagonal_matrix_impl(shared_ptr < matrix_impl <E> > decorated_matrix_ptr):matrix_ptr(decorated_matrix_ptr){
    }

    int getRowNumber() const override {
        return matrix_ptr->getRowNumber();
    }

    int getColumnNumber() const override {
        return matrix_ptr->getColumnNumber();
    }

    E get(int accessed_row, int accessed_column) const override  {
        if (accessed_row < 1 || accessed_row > getRowNumber()) {
            throw "Out of bound row index";
        } else if (accessed_column != accessed_row)
            return getZeroElement<E>();
        else
        {
            return matrix_ptr->get(accessed_row, accessed_row);
        }
    }

    E &get_ref(int accessed_row, int accessed_column) override {
        if (accessed_row < 1 || accessed_row > getRowNumber()) {
            throw "Out of bound row index";
        } else if (accessed_column != accessed_row)
            return getZeroElement<E>();
        else
        {
            return matrix_ptr->get_ref(accessed_row, accessed_row);
        }
    }
};
