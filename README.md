Three classes, Circle, Rectangle, and Triangle, are derived directly from the abstract base class Shape. These derived classes are made concrete by providing implementations for all the pure virtual functions introduced in the abstract base class Shape, in the files circle.hpp/.cpp, rectangle.hpp/.cpp, and triangle.hpp/.cpp.

Class Picture, in the files picture.hpp/.cpp,  is implemented as a doubly linked list of Shape pointers. 
picture.hpp only #includes shape.hpp; it knows nothing about any other kinds of Shapes, like Circle, Rectangle, Triangle, or Square.






# This repository contains all the coding projects
# I could find from before March 2023.
#
# Each README file will contain a short description
# of what each program does. Be aware that some 
# programs do not come with any user input options
