#include <iostream>
using namespace std;

#include "Picture.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"

#define N_TESTS 3

void add_shapes(Picture & pic,int i,int param1,int param2){

    pic.add(new Circle(0,0,"Circle_"+to_string(i),i*param1));
    pic.add(new Rectangle(0,0,"Rectangle_"+to_string(i),i*param1,i*param2));
    pic.add(new Triangle(0,0,"Triangle_"+to_string(i),i*param1,i*param2));
    }
int main(){
Picture collage;
for (int  i = 0; i<=N_TESTS; ++i)
    add_shapes(collage,i,2,3);
cout<<collage.total_area()<<endl;
collage.print_all();
collage.draw_all();
}
