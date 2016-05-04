/*************************************************************************
filename:"rectangle.h", final#2
author: Aliosha Gonzalez
synopsis: This is the interface of the derive class Rectangle. 
**************************************************************************/
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class Rectangle : public Shape
{
        public:
                Rectangle();
                Rectangle(const int& theX, const int& theY, const eColor& theColor,
                                float theBase, float theHeight); //rectangle default color=1
                Rectangle(const Rectangle& r);
                ~Rectangle();
                //accessors
                float getBase() const {return base;}
                float getHeight() const {return height;}
                virtual float getArea() const;
                virtual void print() const {cout << "Rectangle color=" << mColor << " base=" << base 
                        << " height=" << height << endl;}
                void drawObject() const {cout << "Drawing Rectangle\n";}
                //mutators
                void setBase(float theBase) {base = theBase;}
                void setHeight(float theHeight) {height = theHeight;}
                //operators
                const Rectangle& operator=(const Rectangle& rhs);
                const Rectangle operator+(const Rectangle& rhs)const;
                       
        private:
                float base;
                float height;
};

#endif    //RECTANGLE_H
