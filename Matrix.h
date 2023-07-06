
#ifndef MATRIX_H
#define MATRIX_H
using namespace std;

#include "Array.h"
template
<typename T>
class Matrix{
    int rows, cols;
     Array<Array<T> *> matrix;

public:

    bool in_bounds(int row){
        if(row<rows &&row >= 0)
            return true;
        return false;
    
    
    }
    Matrix( int new_rows, int new_cols)
        :rows(new_rows),cols(new_cols),matrix(new_rows){
            for(int i = 0; i<rows; ++i)
                matrix[i] =  new Array<T>(cols);
}
    Matrix(const Matrix & a):rows(a.rows),cols(a.cols),matrix(a.rows){
        for(int i =0;i<rows;++i){
            matrix[i] = new Array<T>(cols);
        }
    }
    
    Matrix & operator =(Matrix & a)=delete;

    int num_rows(){
        return rows;
        }

    int num_cols(){
        return cols;
    }
    
    void fill(T val){
        for(int  i = 0;i<rows;i++){
        //                                      KEEP AN EYE OUT HERE FOR ALLOCATION STUFF
            matrix[i] -> fill(val);
        }
    }

    Array<T> & operator [](int row){
    if (in_bounds(row))
        return * matrix[row];
    else{
         string panic = "Exception operator[](" + to_string(row) + ") Out of Range";
        throw panic;
    }
    }

    Array<T> & operator[](int row)const{
        if (in_bounds(row))
            return * matrix[row];
        else{
            string panic = "Exception operator[]("+to_string(row) + ") Out of Range";
            throw panic;
            }

    }

    void print(ostream & out){
        for(int i = 0; i<rows;i++)
           { matrix[i] -> print(out);
            out<<endl;
   } }

    friend ostream & operator << (ostream & out, Matrix & m){
        m.print(out);
        return out;
        }
    friend ostream & operator <<(ostream & out,Matrix * m){
        m->print(out);
        return out;
    }
    ~Matrix(){
        for(int i =0; i<rows;i++){
            delete matrix[i];

        }
    }

        };
#endif
