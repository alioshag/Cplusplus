/*************************************************************************
filename:"circle.h", final#2
author: Aliosha Gonzalez
synopsis: This is the interface of the derive class Circle. 
**************************************************************************/
#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
#include <iostream>
#include <cstdlib>
using namespace std;
class Circle : public Shape
{
        public:
                Circle();
                Circle(const int& theX, const int& theY, const eColor& theColor,
                                float theRadius); //circle default color=red
                Circle(const Circle& r);
                ~Circle();
                //accessors
                float getRadius() const {return radius;}
                virtual float getArea() const;
                void drawObject() const {cout << "Drawing Circle\n";}
                virtual void print() const {cout << "Circle color=" << mColor << " Radius=" << radius << endl;}
                //mutators
                void setRadius(int theRadius) {radius = theRadius;}
                //operators
                const Circle& operator=(const Circle& rhs);
                const Circle operator+(const Circle& rhs)const;
        protected:                
                float radius;  //radius of the circle
};
#endif    //CIRCLE_H
