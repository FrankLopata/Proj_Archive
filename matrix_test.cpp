#include <iostream>
using namespace std;
#include "Matrix.h"

template
<typename  T,typename FN>


void fill_with_fn(Array<T> & a,FN fn){
    for(int i = 0;i<a.length();++i){
        a[i]=fn(i);
        }
}
template
<typename T,typename FN>
void fill_with_fn(Matrix<T> & a,FN fl){
    for(int i = 0;i<a.num_rows();i++)
        for(int y= 0; y<a.num_cols();y++){
            a[i][y] = fl(i,y);
     }   
}
void test_int_array(){

    Array<int> a{10};
    auto fn = [](int i){return i+1;};
    a.fill(int());
    cout << a <<endl;
    fill_with_fn(a, fn);
    cout<<a<<endl;
    cout<<endl;
}

void test_int_matrix(){
    auto fl = [](int row,int i ) {return (row+1)*(i+1);};
    Matrix<int> m{3,10};
    m.fill(int());
     cout <<m<< endl;
    fill_with_fn(m,fl);
    cout<<m<<endl;
    cout<<endl;
}

void test_double_array()
{
    auto fl = [](double x){return x + 1.1;};
    Array<double> a{8};
    a.fill(double());
     cout << a << endl;
    fill_with_fn(a, fl);
    cout << a << endl;
    cout << endl;
}

void test_double_matrix()
{
    auto fl = [](double x, double y){return (x+1.0) + (y+1.0) / 10;};
    Matrix<double> a{10, 10};
    a.fill(double());
     cout << a << endl;
    fill_with_fn(a, fl);
    cout << a << endl;
    cout<< endl;
}

void test_char_array()
{
    auto fl = [](char a){ return a + 'A';};
    Array<char> ar{26};
    ar.fill(char());
    fill_with_fn(ar, fl);
    cout << ar << endl;
    cout<< endl;
}

void test_char_matrix()
{
    auto fl = [](char a, int i){i=0;return a+'A'+i;};
    Matrix<char> ar{26, 3};
    ar.fill(char());
    cout << ar << endl;
    fill_with_fn(ar, fl);
    cout << ar << endl;
    cout<< endl;
}
void test_exceptions()
{
    try
    {
        Array<char> a{26};
        a[30];
    }
    catch (std::string &e)
    {
        cout << e << endl;
    }
    try
    {
        // generate the exception in Matrix with row
    }
    catch (std::string &e)
    {
        cout << e << endl;
    }
    try
    {
        // generate the exception in Matrix with col
    }
    catch (std::string &e)
    {
        cout << e << endl;
    }
}

void test_extras()
{
    Matrix<int> m{10, 10};
    Matrix<int> newer{m};
    Array<int> a{10};
    cout << &a << endl;
}
#define N 1

int main(){
    for(int i = 1;i<=N; ++i){
    test_int_array();
    test_int_matrix();
    test_char_array();
    test_char_matrix();
    test_double_array();
    test_double_matrix();
    test_exceptions();
    
    test_extras();
    }
} 
