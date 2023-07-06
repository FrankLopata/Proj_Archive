#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include <iostream>
using namespace std;
#include "Shape.h"

class Triangle:public Shape{

protected:
    double height;
    double base;

public:
    Triangle(int cx, int cy, string nm, double b, double h):Shape(cx,cy,nm){
        height=h;
        base =b;
    }

    double area(){
        double out = height*base;
        return out/2;
        }

    void draw(){
        int offset = max(height,base);
        for(int row=0;row<height;row+=2){
            for(int col = 0;col<(offset-row)/2;col++)
                cout<<" ";
            for(int i = 0;i<=row;i++)
                cout<<"*";
            cout<<endl;
        }
    }

    ~Triangle(){};

};

#endif
