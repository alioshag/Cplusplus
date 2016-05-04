/*************************************************************************
 * filename: "circle.h"
 * author: Aliosha Gonzalez
 * synopsis: This is the interface if the derived class Circle. 
 * ************************************************************************/
#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <cstdlib>
#include "shape.h"
using namespace std;

class Circle : public Shape
{
        public:
                Circle();
                Circle(const int& theX, const int& theY, int theRadius);
                Circle(const Circle& c);
                ~Circle() {cout << "Destructor of Circle\n";}
                //accessors
                float getRadius() const {return radius;}
                virtual void draw() const {cout << "draw() Circle\n";}
        private:
                float radius;   //the radius of the circle
};
#endif //CIRCLE_H
