/**************************************************************************
filename: "pointtemplate.h", final#1
authot: aliosha gonzalez
description: This is the intereface for class Point. The implementation is in the 
file "pointtemplate.cpp"


***************************************************************************/
#ifndef POINTTEMPLATE_H
#define POINTTEMPLATE_H
#include <iostream>
#include <cstdlib>
using namespace std;

template<class T>
class Point
{
        public:
                Point(): x(0), y(0){cout << "default CC for Point\n";} //default CC. init with values zero.
                Point(T theX, T theY): x(theX), y(theY) {cout << "Two arg CC for Point template\n";}
                ~Point(){cout << "Destructor for Point template\n";}
                Point<T>(const Point<T>& p) : x(p.getX()), y(p.getY()) {cout << "Copy CC for Point template\n";}
                //operators
                Point<T>& operator=(const Point<T> &rhs);  //assignment operator
                void operator+(T delta); //adds a delta to x and y
                T operator-(const Point<T> &rhs);   //distance btw points
                T operator-(Point<T> &rhs);         //return distance btw points
                //mutators
                void reset_location(T theX, T theY);    //enter new location
                //accessors
                T getX() const {return x;}
                T getY() const {return y;}
                //friend functions
                //print coordinates of a point
                friend ostream& operator<< (ostream &os, const Point<T> &rhs){   
                        os << "x=" << rhs.x << ",  y=" << rhs.y << endl;
                        return os;
                };                               
        private:
                T x; //x and y coordinates   
                T y;
};
#endif   //POINT-TEMPLATE_H
