/**************************************************************************
 * filename: "circle.cpp"
 * author: Aliosha Gonzalez"
 * synopsis: This is the implementation file of the derived class Circle.
 *           The implementation of the derive class Circle is on the file "circle.h"
 * ************************************************************************************/

#include "circle.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Circle::Circle() : Shape(), radius(0) {cout << "Default Constructor for Circle\n";}

Circle::Circle(const int& theX, const int& theY, int theRadius) 
        : Shape(theX, theY), radius(theRadius)
        {cout << "Parameterized Constructor for Circle\n";}
Circle::Circle(const Circle& c): Shape(c) {cout << "Copy Constructor for Cicle\n";}

