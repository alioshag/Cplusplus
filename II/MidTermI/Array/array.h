/*******************************************************************
filename: "array.h" Midterm#3
author: Aliosha Gonzalez
synopsis: This is the interface for class Array. The implementation
          is in the file "array.cpp".
*********************************************************************/ 
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <cstdlib>
using namespace std;

class Array
{
        public:
                Array();   //default CC. Init with size 10.
                Array(int Size);  //array of size = Size created on the heap
                Array(int Size, int Value);  //Size & init Value arg
                ~Array();  //default desctructor
                Array(const Array &rhs);   //copy CC
                //operators   
                Array& operator=(const Array &rhs);   //assigniment operator
                int& operator[](int offSet);   //returns the nth element
                const int& operator[](int offSet) const; //sets value the nth element
                //accessors
                int getSize() const; //Returns array size
                //mutator
                void setResize(int newSize); //resize array
                void decimate(int df); //decimator_factor, remove every jth element & resize
                void interpolate(int interpolator_factor); //insert factor # of zeros
                //friend functions
                friend ostream& operator<<(ostream& out, const Array &rhs); //output
        private:
                int *pType; //for an array of integers, pointer to the heap
                int itsSize; //Array size
};
#endif  //ARRAY_H
