/**************************************************************************
filename: "point.h", final#1
authot: aliosha gonzalez
description: This is the intereface for class Point. The implementation is in the 
file "point.cpp"


***************************************************************************/
#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cstdlib>
using namespace std;

class Point
{
        public:
                Point(): x(0), y(0){cout << "default CC for Point\n";} //default CC. init with values zero.
                Point(int X, int Y): x(X), y(Y) {cout << "Two arg CC for Point \n";}
                ~Point(){cout << "Destructor for Point\n";}
                Point(const Point& p) : x(p.getX()), y(p.getY()) {cout << "Copy CC for Point\n";}
                //operators
                Point& operator=(const Point &rhs);  //assignment operator
                void operator+(int delta); //adds a delta to x and y
                int operator-(const Point &rhs);   //distance btw points
                int operator-(Point &rhs);         //return distance btw points
                //mutators
                void reset_location(int X, int Y);    //enter new location manually
                //accessors
                int getX() const {return x;}
                int getY() const {return y;}
                //friend functions
                friend ostream& operator<<(ostream &os, const Point &X); //print coordinates of a point
        private:
                int x; //x and y coordinates   
                int y;
};
#endif   //POINT_H
