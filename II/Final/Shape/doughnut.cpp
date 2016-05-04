/*****************************************************
filename: "doughnut.cpp", Final#2
author: Aliosha Gonzalez
synopsis: This is the implementation of the derived class Doughnut.
          The interface is on the file "doughnut.h"
 *
 *
 * **************************************************/
#include "doughnut.h"
#include "circle.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

const float pi = 3.1416;

Doughnut::Doughnut() : Circle(), inrad(0) {cout << "Default CC for Doughnut\n";}

Doughnut::Doughnut(const int& theX, const int& theY, const eColor& theColor,
                const float& theRadius,
                float theInrad)
          : Circle(theX, theY, theColor, theRadius), inrad(theInrad)
          {cout << "Parameterized CC for Doughnut\n";}

Doughnut::Doughnut(const Doughnut& d)
        : Circle(d)
        {cout << "Copy CC for Doughnut\n";}

Doughnut::~Doughnut() {cout << "Destructor for Doughnut\n";}        

//operators
const Doughnut& Doughnut::operator=(const Doughnut& rhs)
{
        Circle::operator=(rhs);
        inrad = rhs.getInrad();

        return *this;
}
const Doughnut Doughnut::operator+(const Doughnut& rhs)const
{
        //outter circle radius inherited from class circle
        //newRadius is the outter circle radius for A3=A1+A2 and inner circle radius=inner circle radius of calling obj
        float newRadius = sqrt(radius * radius //radius from outter circle
                          + rhs.radius * rhs.radius  //outter radius of rhs
                          - rhs.inrad * rhs.inrad); //inner radius of rhs
        return Doughnut(x + rhs.x, y + rhs.y, black, newRadius, inrad); //inrad=inrad of calling obj 
}
float Doughnut::getArea() const //virtual
{
        cout << "getArea{} Doughnut\n";
        
        return static_cast<float>(pi * (radius*radius - inrad*inrad));
}
