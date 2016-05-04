/*******************************************************
filename: poly.h Midterm#1   deliver by 07/16/2013
author: aliosha gonzalez
synopsis: Interface of the class Poly
description:

****************************************************************************************/

#ifndef POLY_H
#define POLY_H

#include <cstdlib>
#include <iostream>
 using namespace std;
 

class Poly
{
        private:
                int order;   //order of polynomial
                int *coeff;   //pointer to array of coef on the heap
                              //size of coeff array predicated on (order + 1)
        public:
                Poly();      //default constructor, order=0 & coeff[0]=1
                Poly(int Order, int Default);  //creates Nth order poly inits all coeffs
                Poly(int Order);  //creates Nth order poly inits all coeffs to zero
                Poly(int Order, int *Coeff);     //creates and Nth order poly & inits
                ~Poly();                         //destructor
                Poly(const Poly& rhs);           //copy constructor

                //accessors
                int getOrder() const {return order;}           //get order of poly
                int* get() const {return coeff;}               //returns pointer to coeff array

                //mutators
                void set();//{ /*Query user for input coefficient values*/;}
                void set(int coeff[], int size);

                //operators
                const Poly operator+(const Poly &rhs) const;    //add two polynomials
                const Poly operator-(const Poly &rhs) const;    //subt two polynomials
                const Poly operator*(int scale);    //scale a polynomial (Poly*5)
                const Poly operator*(const Poly &rhs)const;    // mult two polynomials
                bool operator ==(const Poly &rhs)const;   //equality operator
                Poly& operator=(const Poly &rhs);   //assignment operator
                int& operator[](int j);             //return the jth coefficient
                const int& operator[](int j)const;  //return the jth coefficient
                const int operator()(int X)const;          //evaluate  P(x) according

                //friend functions
                friend const Poly operator*(const int lhs, Poly& rhs){return rhs * lhs;}//resolve 5*Poly  
                friend ostream& operator <<(ostream& out, const Poly& rhs);
                friend istream& operator >>(istream& in, Poly& rhs);
};
#endif
