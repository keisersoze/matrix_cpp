// DIAGONL MATRIX //

template <typename E>
class diagonal_matrix_impl : public matrix_impl <E>{

private:

    shared_ptr< matrix_impl<E> > matrix_ptr;

    const zero = 0;

public:

    diagonal_impl(shared_ptr < matrix_impl <E> > decorated_matrix_ptr):matrix_ptr(decorated_matrix_ptr){
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
        } else if (accessed_column != 1) {
            throw "Out of bound column index"; //TODO i messaggi vanno migliorati
        } else if (accessed_column != accessed_row)
            return zero;
        else 
        {
            return matrix_ptr->get(accessed_row, accessed_row);
        }

        
    }
} 