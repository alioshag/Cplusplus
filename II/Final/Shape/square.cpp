/*********************************************************************
filename: "square.cpp", final#2
author: Aliosha Gonzalez
synopsis: This is the implementation of the derived class Square.
          The interface of the derived class square is on the file
          "square.h"
***********************************************************************/
#include "square.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Square::Square() : Shape(), base(0) {cout << "Default CC for Square\n";}

Square::Square(const int& theX, const int& theY, const eColor& theColor,
                float theBase)
           : Shape(theX, theY, yellow), base(theBase)
           {cout << "Parameterized CC for Square\n";}

Square::Square(const Square& s)
        : Shape(s) 
        {cout << "Copy CC for Square\n";}

Square::~Square(){cout << "Destructor for Square\n";}        

//operators
const Square& Square::operator=(const Square& rhs)
{
        Shape::operator=(rhs);
        base = rhs.getBase();

        return *this;
}
const Square Square::operator+(const Square& rhs)const
{
        float newBase = sqrt(base*base + rhs.base*rhs.base);
        
        return Square(x + rhs.x, y + rhs.y, yellow, newBase);  //temp Square
}
float Square::getArea() const //pure virtual function on base class Shape
{
        cout << "getArea() Square\n";
        
        return base * base;
}

