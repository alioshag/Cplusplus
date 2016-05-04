/*************************************************************************
filename:"square.h", final#2
author: Aliosha Gonzalez
synopsis: This is the interface of the derive class Square. 
**************************************************************************/
#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class Square : public Shape
{
        public:
                Square();
                Square(const int& theX, const int& theY, const eColor& theColor,
                                float theBase); //square default color=yellow
                Square(const Square& s);
                ~Square();
                //accessors
                float getBase() const {return base;}
                virtual float getArea() const;
                void drawObject() const {cout << "Drawing Square\n";}
                virtual void print() const {cout << "Square color=" << mColor
                        << " base=" << base << endl;}
                //mutators
                void setBase(float theBase) {base = theBase;}
                //operators
                const Square& operator=(const Square& rhs);
                const Square operator+(const Square& rhs)const;//adds two shapes, the area of the resulted figure its the addition af the areas of the original shapes 
        private:
                float base;
};
#endif    //SQUARE_H
