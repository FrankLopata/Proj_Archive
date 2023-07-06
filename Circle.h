#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include <iostream>
#include <cmath>
using namespace std;
#include "Shape.h"


class Circle:public Shape{

protected: 
    double radius;

public:
    Circle(int cx, int cy,string nm, double rad):Shape(cx,cy,nm){
        radius = rad;
        }

    double area(){
        return 3.14159 * radius * radius;
    }

    void draw(){
        for( int row= -radius; row <= radius; row+=2){
            for(int col = -radius; col <= radius; col++){
                double distance= sqrt(col * col + row * row);
                if( distance <= radius)
                    cout<<"*";
                else
                    cout<<" ";

            }
            cout<< endl;

        }
    }
    ~Circle(){}
};

#endif
