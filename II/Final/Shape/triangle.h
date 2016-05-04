/*************************************************************************
filename:"triangle.h", final#2
author: Aliosha Gonzalez
synopsis: This is the interface of the derive class Triangle. 
          The triangle is a right triangle. 
**************************************************************************/
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class Triangle : public Shape
{
        public:
                Triangle();
                Triangle(const int& theX, const int& theY, const eColor& theColor,
                                float theBase, float theHeight); //triangle default color=1
                Triangle(const Triangle& t);
                ~Triangle();
                //accessors
                float getBase() const {return base;}
                float getHeight() const {return height;}
                virtual float getArea() const;
                virtual void print () const {cout << "Triangle color=" << mColor << " base=" << base
                        << " height=" << height << endl;}
                void drawObject() const {cout << "Drawing Triangle\n";}
                //mutators
                void setBase(float theBase) {base = theBase;}
                void setHeight(float theHeight) {height = theHeight;}
                //operators
                const Triangle& operator=(const Triangle& rhs);
                const Triangle operator+(const Triangle& rhs)const;//the resulted figure has the Area of the sum of the two initial figures areas.
                       
        private:
                float base;
                float height;
};

#endif    //TRIANGLE_H
