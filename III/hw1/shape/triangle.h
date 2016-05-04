/*******************************************************
 * filename: "triangle.h"
 * author: Aliosha Gonzalez
 * synopsis: This is the interface file for the derived class Triangle.
 *        The implementation of this class is on the file "triangle.cpp".
****************************************************/
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class Triangle: public Shape//triangle is assumed to be a right triangle
{
        public:
                Triangle();   //default constructor
                Triangle(const int& theX, const int& theY,float theBase, float theSide);
                Triangle(const Triangle& t);
                ~Triangle() {cout << "Destructor of Triangle\n";}
                //accessor
                float getBase() const {return base;}
                float getSide() const {return side;}
                virtual void draw() const {cout << "draw() Triangle\n";}
        private:
                float base;
                float side;                
};
#endif //TRIANGLE_H

