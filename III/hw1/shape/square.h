/***************************************************************************
 * filename: "square.h"
 * author: Aliosha Gonzalez
 * synopsis: This is the interface for the derive class Square. 
 * ************************************************************************/

#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class Square: public Shape
{
        public:
                Square();
                Square(const int& theX, const int& theY, float theSide);
                Square(const Square& s);
                ~Square() {cout << "Destructor of Square\n";}
                //accessor
                float getSide() const {return side;}
                virtual void draw() const {cout << "draw() Square\n";}
        private:
                float side;   //side of the square
};
#endif //SQUARE_H
