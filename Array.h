#ifndef ARRAY_H
#define ARRAY_H

#include <iomanip>
using namespace std;

template
    <typename T>



class Array
{
    int len;

    T * buf;

public:
    bool in_bounds(int r)const{
        return r<len && r>=0;
}
Array(int new_len)
    : len(new_len), buf(new T[len]){
        fill(T());
    }
    int length(){
        return len;
        }


    T & operator[](int index){
         if (in_bounds(index))
            return buf[index];
        else{
            string oopsie_woopsie = "Exception operator[](" + to_string(index) + ") Out of Range";
            throw oopsie_woopsie;
        }
    }
    T const &operator[](int index) const{
        if (!in_bounds(index)){
            string oopsie_woopsie = "Exception operator[](" + to_string(index) + ") Out of Range";
            throw oopsie_woopsie;
        }
        return buf[index];
    }


    Array(const Array & a){
        len = a.len;
        buf = new T[len];
        for(int i = 0; i < len;i++)
            buf[i] = a.buf[i];
    }

    Array & operator = (Array & a) = delete;

    void fill(T val){
        for (int i = 0;i<len;++i)
            buf[i] = val;
    }
    void print(ostream & out) const{
     for( int i = 0; i < len;++i)
        out << setw(8)<< setprecision(2) << fixed <<right <<buf[i];
    
}
    friend ostream & operator<<(ostream & out, Array * a){
        a->print(out);
        return out;
        }
    friend ostream & operator<<(ostream & out, const Array & a){
        a.print(out);
        return out;
    }
    ~Array(){
        delete[] buf;
    }
};
#endif
