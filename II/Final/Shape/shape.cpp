/******************************************************
filename: "shape.cpp", final#2
author: Aliosha Gonzalez
synopsis: This file is the implementation of the class Shape. 
          The interface of the class Shape is in the file "shape.h" *
***********************************************************/
#include "shape.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

const Shape& Shape::operator=(const Shape& rhs)
{
        cout << "Shape operator=\n";
        if (this == &rhs)
        {
                return *this;
        }
        else
        {
                x = rhs.getX();
                y = rhs.getY();

                return *this;
        };
}
/*******************************
const Shape Shape::operator+(const Shape& rhs)const
{
        cout << "Shape operator+ adds location coordinates\n";

        //return Shape(x + rhs.getX(), y + rhs.getY());
        return *this;
}
************************************/
float getDistance(Shape& S1, Shape& S2)
{
        float xdiff = static_cast<float>(S1.getX()-S2.getX()); //offset on the x coordinates
        float ydiff = static_cast<float>(S1.getY()-S2.getY()); //offset on the y coordinates

        return sqrt(xdiff*xdiff + ydiff*ydiff);
}
