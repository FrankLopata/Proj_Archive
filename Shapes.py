
import math
class interface:
    def centroid(self)-> str:
        #retrives center points of shape. By default it is 0,0
        pass
    def movement(self, x: int, y: int) -> None:
        #changes the centeroid of a shape to the set coordinates
        pass
    def area(self)-> int:
        #calculates variosu areas of shapes
        pass
    def perimeter(self)->int:
        #adds all sides of a shape
        pass
    def point(self, x:int, y:int)->bool:
        #takes an x and y point and checks if they lay within that shape. This factors in for the centroid being shifted
        pass
        

        



#shape classes
class rectangle:
#oriented so that it has two sides running parallel to the x axis and the other two sides running parallel to the y axis.

    def __init__(self, width: int, height : int):
            self._x = width
            self._y = height
            self._point_x=0
            self._point_y=0
            return
    def centroid(self):
        x = str(self._point_x)
        y = str(self._point_y)
        coords =x + "," + y
        return coords
    def movement(self, x: int, y: int) -> None:
        self._point_x = x
        self._point_y = y
        return
    def area(self):
        x= self._x
        return x * self._y
    def perimeter(self):
        return self._x+self._x+self._y+self._y
    def point(self, x:int, y:int):
        rangex= [self._point_x-(self._x/2),self._point_x+(self._x/2)]
        rangey= [self._point_y-(self._y/2),self._point_y+(self._y/2)]
        if(x>=rangex[0] and x<=rangex[1] and y>=rangey[0] and y<=rangey[1]):
            return True
        return False
        

class r_triangle:
#oriented so that each of the two sides other than the hypotenuse run parallel to the x and y axes,
#respectively, and so that the hypotenuse runs from the top-rightmost point to the bottom-leftmost point within the shape.
    def __init__(self, width: int, height: int):
        self._x = width
        self._y = height
        self._point_x=0
        self._point_y=0
        return
    def centroid(self):
        x = str(self._point_x)
        y = str(self._point_y)
        coords =x + "," + y
        return coords
    def movement(self, x: int, y: int) -> None:
        self._point_x = x
        self._point_y = y
        return
    def area(self):
        return (self._x*self._y)/2
    def perimeter(self):
        c_side= math.sqrt((self._x**2) + (self._y**2))
        return c_side + self._x + self._y

    def point(self,x:int,y:int):
        rangex1= self._point_x-(self._x/2)
        rangex2 = self._point_x+(self._x/2)
        rangey1= self._point_y-(self._y/2)
        rangey2 = self._point_y+(self._y/2)
        if(rangex1>x or rangey1>y or x>rangex2 or y>rangey2):
            return False
        if(rangex2/2>x and rangey2/2<y):
            return False
        return True
  


class pentagon:
#oriented so that its bottommost side runs parallel to the x axis. 5 sides.
    def __init__(self, width:int, height:int):
        #Takes the width and hight of one right triangle inside the pentagon, with the width beign half of the
        #side length
        self._x = width
        self._y = height
        self._len = width * 2
        self._point_x=0
        self._point_y=0
        return
    def centroid(self):
        x = str(self._point_x)
        y = str(self._point_y)
        coords =x + "," + y
        return coords
    def movement(self, x: int, y: int) -> None:
        self._point_x = x
        self._point_y= y
        return
    def area(self):
       return 10 * ((self._x * self._y)/2)
    def perimeter(self):
        return self._len * 5
    def point(self, x:int, y:int):
        if(x<self._point_x-(self._len/2)):
            return False
        if(x>self._point_x+(self._len/2)):
            return False
        if(y<self._point_y-(self._len)):
            return False
        if(y>self._point_y+self._len):
            return False
        return True


def test_rect():
    shape= rectangle(2,4)
    assert shape.centroid() =="0,0"
    assert shape.area() == 8
    assert shape.perimeter()==12
    assert shape.point(1,1) == True
    shape.movement(3,7)
    assert shape.area() == 8
    assert shape.perimeter()==12
    assert shape.centroid() == "3,7"
    assert shape.point(1,1) == False
test_rect()
def test_tri():
    shape= r_triangle(3,4)
    assert shape.centroid() =="0,0"
    assert shape.area() == 6
    assert shape.perimeter()== 12
    assert shape.point(0,0) == True
    shape.movement(3,7)
    assert shape.area() == 6
    assert shape.perimeter()==12
    assert shape.centroid() == "3,7"
    assert shape.point(1,1) == False
test_tri()
def test_penta():
    shape= pentagon(2,4)
    assert shape.centroid() =="0,0"
    assert shape.area() == 40
    assert shape.perimeter()== 20
    assert shape.point(0,0) == True
    shape.movement(3,7)
    assert shape.area() == 40
    assert shape.perimeter()==20
    assert shape.centroid() == "3,7"
    assert shape.point(1,1) == False
test_penta()
