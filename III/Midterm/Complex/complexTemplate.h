/*********************************************************
 * filename: "complexTemplate.h"
 * author: Aliosha Gonzalez
 * synopsis: This is the interface and implementation of the class Complex. 
 * ***********************************************************/
#ifndef COMPLEXTEMPLATE_H
#define COMPLEXTEMPLATE_H

#include <iostream>
#include <cstdlib>
using namespace std;
//#define _DEBUG
template<class T>
class Complex
{
        public:
                //constructors and destuctors
                Complex();  //default
                Complex(T theR, T theI);  //parameterized
                Complex(const Complex<T> &c);    //copy constructor
                ~Complex();               //Destructor
                //member arithmetic functions
                const Complex operator+(const Complex<T> &rhs)const{return Complex<T>(R+rhs.R, I+rhs.I);}
                const Complex operator-(const Complex<T> &rhs)const{return Complex<T>(R-rhs.R, I-rhs.I);}
                const Complex operator*(const Complex<T> &rhs)const{
                  return Complex<T>((R*rhs.R - I*rhs.I), (R*rhs.I + I*rhs.R));}
                //const Complex operator/(const Complex<T> &rhs)const{//lhs * 1/rhs  division    
                //  return Complex<T>(*this * Complex(rhs.R / (rhs.R*rhs.R - rhs.I*rhs.I),
                //                                -rhs.I / (rhs.R*rhs.R - rhs.I*rhs.I)));}
                const Complex operator/(const Complex<T> &rhs)const{//lhs * 1/rhs  division   
                  return Complex<T>((R*rhs.R + I*rhs.I) / (rhs.R*rhs.R + rhs.I*rhs.I),
                                    (I*rhs.R - R*rhs.I) / (rhs.R*rhs.R + rhs.I*rhs.I));}
                const Complex operator+=(const Complex<T> &rhs){R+=rhs.R;I+=rhs.I;return *this;}
                const Complex operator-=(const Complex<T> &rhs){R-=rhs.R;I-=rhs.I;return *this;}
                const Complex operator*=(const Complex<T> &rhs){
                        int newR = R*rhs.R - I*rhs.I; //holds the new R in newR
                        I = R*rhs.I + I*rhs.R;
                        R = newR;
                        return *this;}
                Complex& operator=(const Complex<T> &rhs);        
                //accesors
                T getReal()const{return R;}
                T getImag()const{return I;}
                //mutators
                void setData(T theR, T theI){R=theR;I=theI;}
                //Logical member functions
                bool operator==(const Complex<T> &rhs){if (R==rhs.R && I==rhs.I) return true;
                                                    return false;}
                bool operator!=(const Complex<T> &rhs){return !(*this==rhs);}
                //friends
               friend ostream& operator<<(ostream &Out, const Complex<T> &rhs){
                        Out << rhs.R << " + " << rhs.I << "j"; return Out;}
        private:
                T R;   //real part
                T I;   //imaginary part
};
template<class T>
Complex<T>::Complex(): R(0), I(0)
{        
#ifdef _DEBUG
        cout << "Default Constructor\n";
#endif
}
template<class T>
Complex<T>::Complex(T theR, T theI)
        :R(theR), I(theI)
{
#ifdef _DEBUG
        cout << "Parameterized Constructor\n";
#endif
}
template<class T>
Complex<T>::Complex(const Complex<T> &c)
        :R(c.R), I(c.I)
{
#ifdef _DEBUG
        cout << "Copy Constructor\n";
#endif
}
template<class T>
Complex<T>::~Complex()
{
#ifdef _DEBUG
        cout << "Destructor\n";
#endif
}
template<class T>
Complex<T>& Complex<T>::operator=(const Complex<T> &rhs)
{
        if (this == &rhs)
                return *this;
        R = rhs.R;
        I = rhs.I;
        return *this;
}

template<>
class Complex<char>
{
        private:
                char c;
                int mask;  //0-256 dec for 8bit mask
        public:
                Complex(char theChar, int theMask):mask(theMask)
                {
                        if ((theChar >= 'A' && theChar <= 'Z') 
                             || (theChar >='a' && theChar <='z')
                             || (theMask >= 0 && theMask >=256))   
                        {
                                
                                c = theChar ^ mask;
                        }else
                        {
                                cerr << "char or mask out of range. Program abort!\n";
                                exit(1);
                        }
                }
                char getChar(){return c;}   //returns encrypted char
                //operator
                char operator^(int theMask){return c ^ theMask;}
};
#endif     //COMPLEX_H

        
