/*********************************************************
 * filename: "complex.h"
 * author: Aliosha Gonzalez
 * synopsis: This is the interface and implementation of the class Complex. 
 * ***********************************************************/
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cstdlib>
using namespace std;
#define _DEBUG
class Complex
{
        public:
                //constructors and destuctors
                Complex();  //default
                Complex(int theR, int theI);  //parameterized
                Complex(const Complex &c);    //copy constructor
                //Complex(char c, int mask);    //char and mask constructor
                ~Complex();               //Destructor
                //member arithmetic functions
                const Complex operator+(const Complex &rhs)const
                {
                        cout << "this= " << *this << endl;
                        cout << "rhs=  " << rhs << endl;
                        return Complex(R+rhs.R, I+rhs.I);}
                const Complex operator-(const Complex &rhs)const{return Complex(R-rhs.R, I-rhs.I);}
                const Complex operator*(const Complex &rhs)const{
                  return Complex((R*rhs.R - I*rhs.I), (R*rhs.I + I*rhs.R));}
                const Complex operator/(const Complex &rhs)const{//lhs * 1/rhs  division    
                  return Complex(*this * Complex(rhs.R / (rhs.R*rhs.R - rhs.I*rhs.I),
                                                -rhs.I / (rhs.R*rhs.R - rhs.I*rhs.I)));}
                const Complex operator+=(const Complex &rhs){R+=rhs.R;I+=rhs.I;return *this;}
                const Complex operator-=(const Complex &rhs){R-=rhs.R;I-=rhs.I;return *this;}
                const Complex operator*=(const Complex &rhs){
                        int tempR = R*rhs.R - I*rhs.I; //hold initial value of R
                        I = R*rhs.I + I*rhs.R;
                        R = tempR;
                        return *this;}
                Complex& operator=(const Complex &rhs);        
                //accesors
                int getReal()const{return R;}
                int getImag()const{return I;}
                //mutators
                void setData(int theR, int theI){R=theR;I=theI;}
                //Logical member functions
                bool operator==(const Complex &rhs){if (R==rhs.R && I==rhs.I) return true;
                                                    return false;}
                bool operator!=(const Complex &rhs){return !(*this==rhs);}
                //friends
               friend ostream& operator<<(ostream &Out, const Complex &rhs){
                        Out << rhs.R << " + " << rhs.I << "j"; return Out;}
        private:
                int R;   //real part
                int I;   //imaginary part
};
Complex::Complex(): R(0), I(0)
{        
#ifdef _DEBUG
        cout << "Default Constructor\n";
#endif
}
Complex::Complex(int theR, int theI)
        :R(theR), I(theI)
{
#ifdef _DEBUG
        cout << "Parameterized Constructor\n";
#endif
}
Complex::Complex(const Complex &c)
        :R(c.R), I(c.I)
{
#ifdef _DEBUG
        cout << "Copy Constructor\n";
#endif
}
Complex::~Complex()
{
#ifdef _DEBUG
        cout << "Destructor\n";
#endif
}
Complex& Complex::operator=(const Complex &rhs)
{
        if (this == &rhs)
                return *this;
        R = rhs.R;
        I = rhs.I;
        return *this;
}
#endif     //COMPLEX_H
