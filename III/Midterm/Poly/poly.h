/***********************************************************
filename: "poly.h"
author: Aliosha Gonzalez
synopsis: This is the interface file for the class Poly. The implementation
          will be on the file "poly.cpp"
***********************************************************/
#ifndef POLY_H
#define POLY_H

#include <iostream>
#include <cstdlib>
using namespace std;

class Poly 
{
        public:
                Poly();                           //ok default constructor- order=0 & coeff[0]=1
                Poly(int Order, int Default = 0); //ok creates Nth order poly and inits all coeffs
                Poly(int Order, int* Coeff);      //ok creates an Nth polynomial & inits
                Poly(const Poly& p);              //ok Copy Constructor
                ~Poly();                          //ok destructor
                //mutators 
                void set();                       //ok Query user for coeff values)
                void set(int coeff[], int size);  //ok
                //accessors
                int getOrder() {return order;} //ok get order of polynomial
                int* get(int* coeff_external); //ok copies poly coeff values to external array
                //overloaded operators
                const Poly operator+(const Poly &rhs) const;//ok add two polynomials
                const Poly operator-(const Poly &rhs) const;//ok subt two polynomials
                const Poly operator*(const int scale)const; //ok scale a polynamial
                const Poly operator*(const Poly &rhs)const; //ok mult two polynomials
                const bool operator==(const Poly &rhs)const;//ok equality operator
                const int operator[](const int I)const;     //ok returns the Ith coeff
                int& operator[](int I);            //ok assign int into lvalue[] operand
                const int operator()(int X)const;  //ok evaluate P(x) accordinly
                Poly& operator=(const Poly &rhs);  //ok assigment operator
                //friends functions
                friend ostream& operator<<(ostream &Out, const Poly &rhs);//ok
                friend const Poly operator*(const int lhs, Poly &rhs){return rhs*lhs;}
                
        private:
               int order;    //order of the polinomial
               int size;     //order+1
               int* coeff;    //pointer to array of coeff on the heap
};
#endif  //POLY_H
