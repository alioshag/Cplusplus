/*********************************************************
filename: "doughnut.h", final#2
author: Aliosha Gonzalez
synopsis: This is the interface of the derive class Doughnut, which
          derived from class Circle which derive from base class Shape.
          The implementation of the class Doughnut is on "doughnut.cpp" file.
**********************************************************/
#ifndef DOUGHNUT_H
#define DOUGHNUT_H
#include "circle.h"
#include <iostream>
#include <cstdlib>
using namespace std;
class Doughnut : public Circle
{
        public:
                Doughnut();
                Doughnut(const int& theX, const int& theY, const eColor& theColor, 
                                const float& theRadius,
                                float theInrad); //doughnut default color black
                Doughnut(const Doughnut& d);
                ~Doughnut();
                //accessors
                float getInrad() const {return inrad;}//return the inner radius
                virtual float getArea() const;
                virtual void print() const {cout << "Doughnut color=" << mColor
                        << " Radius=" << radius << " Inner radius=" << inrad << endl;}
                void drawObject() const {cout << "Drawing Doughnut\n";}
                //mutators
                void setInrad(float theInrad) {inrad = theInrad;}//sets the inner radius
                //operators
                const Doughnut& operator=(const Doughnut& rhs);
                const Doughnut operator+(const Doughnut& rhs)const;
        private:
                float inrad;        //inner radius circle
};
#endif  //DOUGHNUT_H
