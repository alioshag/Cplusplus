/***************************************************************************
filename: "shape.h", hw1
author: Aliosha Gonzalez
synopsis: This is the interface of a base class Shape. The implementation is on the file "shape.cpp"
*******************************************************************************/

#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <cstdlib>
using namespace std;

class Shape
{
        public:
                Shape(): x(0), y(0) {cout << "Default Constructor for Shape\n";}
                Shape(int theX, int theY)
                        : x(theX), y(theY) {cout << "Parameterized Constructor for Shape\n";}
                Shape(const Shape &s)
                        :x(s.getX()), y(s.getY()) {cout << "Copy Constructor for Shape\n";}
                virtual ~Shape() {cout << "Destructor of Shape\n";}
                //accessors
                int getX() const {return x;}
                int getY() const {return y;}
                virtual void draw() const = 0;// {cout << "draw from Shape\n";}
                //mutators
                //operators

        private:
                int x;   //x and y  coordinates of the location 
                int y;
};
#endif //SHAPE_H
