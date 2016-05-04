/****************************************************************************
filename: "pointtemplate.cpp", final#1
author: Aliosha Gonzalez
synopsis: This is the implementation of the class Point. The interface is in the file
         "pointtemplate.h"
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
template<class T>
Point<T>& Point<T>::operator=(const Point<T> &rhs)
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
template<class T>
void Point<T>::operator+(T Delta)
{
        cout << "operator+ Delta\n";
        x = getX() + Delta;
        y = getY() + Delta;
}
template<class T>
T Point<T>::operator-(const Point<T> &rhs)
{
        cout << "operator-(const Point &rhs)\n";
        double d;   //distance
        d = sqrt(static_cast<double>((x-rhs.x)*(x-rhs.x) + (y-rhs.y)*(y-rhs.y)));
        return static_cast<int>(d);
}
template<class T>
T Point<T>::operator-(Point<T> &rhs)
{
        cout << "operator-(Point<T> &rhs)\n";
        double d;   //distance
        d = sqrt(static_cast<double>((x-rhs.x)*(x-rhs.x) + (y-rhs.y)*(y-rhs.y)));
        return static_cast<T>(d);
}
