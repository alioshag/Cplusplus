/*********************************************************************
 * filename: "square.cpp"
 * author: Aliosha Gonzalez
 * synopsis: This is the implementation file of the derived class Square. The interface 
 *          for the class Square is on the file "square.h".
 * ***********************************************************************/
#include "square.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Square::Square() : Shape(), side(0) {cout << "Default Constructor for Square\n";}

Square::Square(const int& theX, const int& theY, float theSide)
        : Shape(theX, theY), side(theSide)
         {cout << "Paremeterized Constructor for Square\n";}
Square::Square(const Square& s)
        : Shape(s) {cout << "Copy Constructor for Square\n";}
