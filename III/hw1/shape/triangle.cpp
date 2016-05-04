/*********************************************************************
 * filename: "triangle.cpp"
 * author: Aliosha Gonzalez
 * synopsis: This is the implementation file for the derived class Triangle. The interface is on the file "triangle.h"
 *******************************************************/
#include "triangle.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Triangle::Triangle(): Shape(), base(0), side(0)
        {cout << "Default Constructor for Triangle\n";}

Triangle::Triangle(const int& theX, const int& theY, float theBase, float theSide)
        :Shape(theX, theY), base(theBase), side(theSide)
         {cout << "Parameterized Constructor for Triangle\n";}
Triangle::Triangle(const Triangle& t)
        : Shape(t) {cout << "Copy Constructor for Triangle\n";}

