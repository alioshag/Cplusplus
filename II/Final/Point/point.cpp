/****************************************************************************
filename: "point-template.cpp", final#1
author: Aliosha Gonzalez
synopsis: This is the implementation of the class Point. The interface is in the file
         "point-template.h"
*******************************************************************************/
#include "pointtemplate.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//mutators
template<class T>
void Point<T>::reset_location(T theX, T theY)
{
        x = theX;
        y = theY;
}
//operators
Point<T>& Point::operator=(const Point<T> &rhs)
{
        cout << "operator= of Point template\n";
        if (this == &rhs) //if the right side is the same as the left side
        {
                return *this;
        }
        else
        {
                x = rhs.getX();  //deep copy instead of shallow copy-->(x=rhs.x)
                y = rhs.getY();  //deep copy 

                return *this;
        }
}
void Point<T>::operator+(T Delta)
{
        cout << "operator+ Delta\n";
        x = getX() + Delta;
        y = getY() + Delta;
}
T Point<T>::operator-(const Point<T> &rhs)
{
        cout << "operator-(const Point &rhs)\n";
        double d;   //distance
        d = sqrt(static_cast<double>((x-rhs.x)*(x-rhs.x) + (y-rhs.y)*(y-rhs.y)));
        return static_cast<int>(d);
}
T Point<T>::operator-(Point<T> &rhs)
{
        cout << "operator-(Point &rhs)\n";
        double d;   //distance
        d = sqrt(static_cast<double>((x-rhs.x)*(x-rhs.x) + (y-rhs.y)*(y-rhs.y)));
        return static_cast<int>(d);
}
ostream& operator<<(ostream &os, const Point<T> &rhs)
{
        os << "x=" << rhs.x << ",  y=" << rhs.y << endl;

        return os;
}
