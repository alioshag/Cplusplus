/***********************************************************************
filename: "shape.h", Final#2
author: Aliosha Gonzalez
synopsis: This is the interface of the base class Shape. The implementation is on the file
         "shape.cpp"


*******************************************************************/
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <cstdlib>
using namespace std;

enum eColor {none = 0, red, orange, yellow, green, black, ivory, violet};
//circle = red
//rectangle = orange
//square = yellow
//right triangle = green
//doughnut = black
class Shape
{
        public:
                Shape() : x(0), y(0), mColor(none) {cout << "Default CC for Shape\n";} 
                Shape(int theX, int theY, eColor theColor = none)
                        :x(theX), y(theY), mColor(theColor) {cout << "Parameterized CC for Shape\n";}
                Shape(const Shape &s) :x(s.getX()), y(s.getY()), mColor(s.getColor()) {cout << "Copy CC for Shape\n";}
                virtual ~Shape() {cout << "Destructor of Shape\n";}
                //accessors
                int getX() const {return x;}  
                int getY() const {return y;}
                eColor getColor() const {return mColor;}
                virtual float getArea() const = 0;  //pure virtual function which makes Shape an abstract class
                virtual void print() const {cout<< "\nError: print function called for an"
                                                << " undifferentiated shape. Aborting the program.\n"; exit(1);}
                virtual void drawObject() const {cout << "drawObject in Shape\n";}
                //mutators
                void ResetLocation(int deltaX, int deltaY) {x = deltaX;y = deltaY;}
                void ResetColor(eColor color) {mColor = color;}
                //operators
                const Shape& operator=(const Shape& rhs);
                //const Shape operator+(const Shape& rhs)const;
                //friends
                friend float getDistance(Shape& S1, Shape& S2);  //calculates the distance btw two Obj of class Shape 
        protected:
                int x;
                int y;
                eColor mColor;
};
#endif //SHAPE_H
