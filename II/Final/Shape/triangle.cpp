/*********************************************************************
filename: "triangle.cpp", final#2
author: Aliosha Gonzalez
synopsis: This is the implementation of the derived class Triangle.
          The interface of the derived class triangle is on the file
          "triangle.h"
***********************************************************************/
#include "triangle.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Triangle::Triangle() : Shape(), base(0), height(0) {cout << "Default CC for Triangle\n";}

Triangle::Triangle(const int& theX, const int& theY, const eColor& theColor,
                float theBase, float theHeight)
           : Shape(theX, theY, green), base(theBase), height(theHeight)
           {cout << "Parameterized CC for Triangle\n";}

Triangle::Triangle(const Triangle& t)
        : Shape(t) 
        {cout << "Copy CC for Triangle\n";}

Triangle::~Triangle(){cout << "Destructor for Triangle\n";}        

//operators
const Triangle& Triangle::operator=(const Triangle& rhs)
{
        Shape::operator=(rhs);
        base = rhs.getBase();
        height = rhs.getHeight();

        return *this;
}
const Triangle Triangle::operator+(const Triangle& rhs)const
{
        float newHeight = (base*height + rhs.base*rhs.height) / base;
        
        return Triangle (x + rhs.x, y + rhs.y, green, base, newHeight);  //temp Triangle used base and newHeight to make A3=A1+A2
}
float Triangle::getArea() const //pure virtual function on base class Shape
{
        cout << "getArea() Triangle\n";
        
        return base * height / 2; //triangle area
}

