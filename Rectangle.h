#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include <iostream>
using namespace std;
#include "Shape.h"


class Rectangle: public Shape{
protected:
    double width;
    double length;
public:
    Rectangle(int cx, int cy, string nm,double h,double w):Shape(cx,cy,nm){width = w;
        width = w;
        length = h;
        }
    double area(){
        return width * length;
    }

    void draw(){
        for(int row = 0; row< width; row+=2){

            for(int col = 0; col < length; col++)
                cout<<"*";
            cout<<endl;
            }


    }

    ~Rectangle(){}
};
#endif
