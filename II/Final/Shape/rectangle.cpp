/*********************************************************************
filename: "rectangle.cpp", final#2
author: Aliosha Gonzalez
synopsis: This is the implementation of the derived class Rectangle.
          The interface of the derived class rectangle is on the file
          "rectangle.h"
***********************************************************************/
#include "rectangle.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Rectangle::Rectangle() : Shape(), base(0), height(0) {cout << "Default CC for Rectangle\n";}

Rectangle::Rectangle(const int& theX, const int& theY, const eColor& theColor,
                float theBase, float theHeight)
           : Shape(theX, theY, orange), base(theBase), height(theHeight)
           {cout << "Parameterized CC for Rectangle\n";}

Rectangle::Rectangle(const Rectangle& r)
        : Shape(r) 
        {cout << "Copy CC for Rectangle\n";}

Rectangle::~Rectangle(){cout << "Destructor for Rectangle\n";}        

//operators
const Rectangle& Rectangle::operator=(const Rectangle& rhs)
{
        Shape::operator=(rhs);
        base = rhs.getBase();
        height = rhs.getHeight();

        return *this;
}
const Rectangle Rectangle::operator+(const Rectangle& rhs)const
{
        //R3=R1+R2, I will keep base3=base1 and will find height3 that 
        //makes the A3=A1+A2
        float newHeight = (base*height + rhs.base*rhs.height) / base;
        
        return Rectangle (x + rhs.x, y + rhs.y, orange, 
                        base, newHeight);  //temp Rectangle base=base1
}
float Rectangle::getArea() const //pure virtual function on base class Shape
{
        cout << "getArea() Rectangle\n";
        
        return base * height;
}

