/*********************************************************************
filename: "circle.cpp", final#2
author: Aliosha Gonzalez
synopsis: This is the implementation of the derived class Circle.
          The interface of the derived class Circle is on the file
          "circle.h"
***********************************************************************/
#include "circle.h"
#include <iostream>
#include <cstdlib>
using namespace std;

const float pi = 3.1416;

Circle::Circle() : Shape(), radius(0) {cout << "Default CC for Circle\n";}

Circle::Circle(const int& theX, const int& theY, const eColor& theColor,
                float theRadius)
           : Shape(theX, theY, red), radius(theRadius)
           {cout << "Parameterized CC for Circle\n";}

Circle::Circle(const Circle& c)
        : Shape(c) 
        {cout << "Copy CC for Circle\n";}

Circle::~Circle(){cout << "Destructor for Circle\n";}        

//operators
const Circle& Circle::operator=(const Circle& rhs)
{
        Shape::operator=(rhs);
        radius = rhs.getRadius();

        return *this;
}
const Circle Circle::operator+(const Circle& rhs)const
{
        //r : radius of the resulting circle
        float r = sqrt(radius*radius + rhs.radius*rhs.radius);
        
        return Circle(x + rhs.x, y + rhs.y, red, r);  
}
float Circle::getArea() const //pure virtual function on base class Shape
{
        cout << "getArea() Circle\n";
        
        return pi * radius * radius;//pi declare at the top
}
