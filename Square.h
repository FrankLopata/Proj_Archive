#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include <string>
using namespace std;
#include "Rectangle.h"


class Square:public Rectangle{

public:
    Square(int cx,int cy,string nm,int side):Rectangle(cx,cy,nm,side,side){}








};




#endif
