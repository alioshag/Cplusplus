/**************************************************************
filename: poly.cpp    Midterm#1
author: aliosha gonzalez
synopsis: This is the implementation of the class Poly.
          The interface of the class Poly is in the file Poly.h
********************************************************************/
#include "poly.h"
#include <iostream>
#include <cstdlib>
//#include <complex>

using namespace std;

Poly::Poly() : order(0)   //defualt 
{
        coeff = new int[order+1];
        coeff[0] = 1;
        //cout << "default CC "<< endl;
}
Poly::~Poly()
{
        //cout << "Destructor" << endl;
        delete [] coeff;
}
//ask question regarding this Constructor
//if coeff is not provided initialize every coeff to zero.
Poly::Poly(int Order)
{
        //cout << "One integer argument CC" << endl;
        order = Order;
        coeff = new int[order+1];
        for (int i = order; i >= 0; i--)
                coeff[i] = 0;
}
Poly::Poly(int Order, int Default)
{
        //cout << "Two integer argument CC" << endl;
        order = Order;
        coeff = new int[order+1];
        for (int i = 0; i <= order; i++)
                coeff[i] = Default;
}
Poly::Poly(int Order, int *Coeff)
{
        //cout << "One integer, one int* argument CC" << endl;
        order = Order;

        coeff = new int[order+1];
        
        for (int i = 0; i <= order; i++)
                coeff[i] = Coeff[i];
}
Poly::Poly(const Poly& rhs) //copy CC
{
        cout << "Copy CC  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
        order = rhs.order;
        coeff = new int[order+1];
        for (int i = 0; i <= order; i++)
                coeff[i] = rhs.coeff[i];
}
void Poly::set()
{
        cout << "Enter order of polynomial ";
        cin >> order;
                
        coeff  = new int[order+1];
        for (int i = 0; i <= order; i++)
        {
                cout << "Enter the coeff with order " << i << endl;
                cin >> coeff[i];
        }
}
void Poly::set(int Coeff[], int size)
{
        order = size;
        coeff = new int[order+1];
        
        for (int i = 0; i <= order; i++)
                coeff[i] = Coeff[i];
}
const Poly Poly::operator+(const Poly &rhs) const
{
        int bigOrder;     //hold the value of the bigger order poly
        typedef int* ptr;
        ptr a, bPolyptr;  //a points to an array with size equal to bigger poly but holds d values of smaller order poly
                          //bPolyptr points to the array of poly with bigger order 
        
        if (order > rhs.order)
        {       //lhs bigger order, create array and add poly of rhs
                a = new int[order+1];
                bigOrder = order;
                bPolyptr = coeff;
                for (int i = 0; i <= rhs.order; i++)
                        a[i] = rhs.coeff[i];
        }else
        {       //rhs bigger or equal order, create array and add poly of lhs
                a = new int[rhs.order+1];
                bigOrder = rhs.order;
                bPolyptr = rhs.coeff;
                for (int i = 0; i <= order; i++)
                        a[i] = coeff[i];
        }
        
        for (int i = 0; i <= bigOrder; i++)
                a[i] = a[i] + bPolyptr[i];
        
        return Poly(bigOrder, a);
                
}
const Poly Poly::operator-(const Poly &rhs)const
{
        int bigOrder;     //hold the value of the bigger order poly
        typedef int* ptr;
        ptr a;  //a points to an array with size equal to bigger poly but holds d values of smaller order poly
        if (order > rhs.order)
        {       //lhs bigger order, creates a lhs poly Nth array with the rhs coeffs
                a = new int[order+1];
                bigOrder = order;
                for (int i = 0; i <= order; i++)
                        a[i] = coeff[i];
                
                for (int i = 0; i <= rhs.order; i++)
                        a[i] = a[i] - rhs.coeff[i];
        }else
        {       //rhs bigger or equal order, create a rhs Nth array and lhs coeff
                a = new int[rhs.order+1];
                bigOrder = rhs.order;
                for (int i = 0; i <= rhs.order; i++)
                        a[i] = -rhs.coeff[i];   //fill a[] with coeff of bigger order poly
                
                for (int i = 0; i <= order; i++)
                        a[i] = coeff[i] + a[i];
        }
        
        return Poly(bigOrder, a);
}
const Poly Poly::operator*(const int scale) //scale a poly
{
        typedef int* IntPtr;
        IntPtr a;
        a = new int[order+1];
        for (int i=0; i <= order; i++)
                a[i] = coeff[i] * scale;

        return Poly(order, a);
}
const Poly Poly::operator*(const Poly &rhs)const
{
        typedef int* newPtr;
        newPtr a;
        a = new int[order + rhs.order+1];         //the result poly will be of [order + rhs.order]
        for (int i=0; i <= order+rhs.order; i++)  //initialize array a[] with zeros
                a[i] = 0;
                
        for (int i=0; i <= order; i++)   //loops through the coeffs of the lhs poly
        {
                for (int j=0; j <= rhs.order; j++)  //loops through the coeffs of the rhs poly
                {
                        //puts the values of multiplication on a[] corresponding order location
                        //cout << a[i+j] << "  " << coeff[i] << "   " << rhs.coeff[j] << endl;
                        a[i+j] = a[i+j] + (coeff[i] * rhs.coeff[j]);
                }
        }
        //for (int i=0; i <= order+rhs.order; i++)
        //        cout << a[i] << " ";
        //cout << endl;
        return Poly(order+rhs.order, a);
}
bool Poly::operator ==(const Poly &rhs)const
{
       if (order != rhs.order)
               return false;
       
       for (int i = 0; i <= order; i++)
       {
               if (coeff[i] != rhs.coeff[i])
                       return false;
       }
       cout << "TRUE\n";
       return true;
}
        
Poly& Poly::operator =(const Poly &rhs)
{
        //cout << "operator =\n";
        if (this == &rhs)  //if the right side is the same as the left side
        {
                return *this;
        }
        else
        {
                order = rhs.order;
                delete [] coeff;
                coeff = new int[rhs.order+1];

                for (int i=0; i <= order; i++)
                        coeff[i] = rhs.coeff[i];
                
                
                return *this;
        }
}
int& Poly::operator[](int j)  //a[i] = 5;
{
        //cout << "operator[]\n";
        if (j<0 || j>order)
        {
                cerr << "Program abort!" << "Illegal index in array." << endl;
                exit(0);
        }
        return coeff[j];
}
const int& Poly::operator[](int j) const   //i = a[i]
{
        if (j<0 || j>order)
        {
                cerr << "Program abort!" << "Illegal index in array." << endl;
                exit(0);
        }
       return coeff[j];
}
const int Poly::operator()(int X) const
{
        double total=0;
        for (int i = 0; i <= order; i++)
        {
                total += coeff[i] * pow(static_cast<double>(X), static_cast<double>(i));
                //cout << "coeff[" << i << "]= " << coeff[i] << "     total= " << total << endl;
        }

        cout << endl;

        return static_cast<int>(total);
}
ostream& operator <<(ostream& out, const Poly& rhs)
{
        for (int i = rhs.order; i >= 0; i--)
        {
                if (rhs.coeff[i] !=0)         //if coeff = 0 skip to the next
                {
                        if (rhs.coeff[i] > 0)   //print "+", t negative sign provided by neg coeff
                        {
                                out << "+";
                        }
                        out << rhs.coeff[i];   //only print coeff !=1
                        if (i > 0)     //if the power is zero, does not print "X"
                        {
                                out << "X";
                        }
                        if (i > 1)
                        {
                                out << "^" << i;
                        }
                }
        
        }
        return out;
}
istream& operator >>(istream& in, Poly& rhs)
{
        int newCoeff;
        cin >> newCoeff;
        //cout << "newCoeff= " << newCoeff << endl;

        char x;
        in >> x;
        //cout << "x= " << x << endl;
        if (x != 'x' && x != 'X')
        {
                cerr << "Illegal operation.\n";
                exit(1);
        }
        
        char pw;
        in >> pw;
        //cout << "pw= " << pw << endl;
        if (pw != '^')
        {
                cerr << "Illegal operation.\n";
                exit(1);
        }
        
        int rOrder;
        cin >> rOrder;
        rhs.order = rOrder;
        int bOrder = rOrder;    //before order, keep record of order before last entered 
        
        typedef int* IntPtr;
        IntPtr a;

        a = new int[rOrder+1];
        int a_index = rOrder;   //index on array a
        a[rhs.order] = newCoeff;
        //cout << "a[" << rhs.order << "]=" << a[rhs.order] << endl;

        for (int i = 0; i <= rhs.order-1; i++)
        {
                cin >> newCoeff;
                cin >> x;
                if (x != 'x' && x!= 'X')
                {
                        cerr << "Illegal operation. Missing X or x\n";
                        exit(1);
                }
                cin >> pw;
                if (pw != '^')
                {
                        cerr << "Illegal operation. Missing '^'\n";
                        exit(1);
                }
                
                cin >> rOrder;
                if (rOrder+1 != bOrder)
                {
                        cout << "Illegal operation. No consecutives power orders.\n";
                        exit(1);
                }else
                {
                        --bOrder;
                }
                a[rhs.order-1-i] = newCoeff;
                //cout << "a[" << rhs.order-1-i << "]=" << a[rhs.order-1-i] << endl;
        }

        for (int i = 0; i <= rhs.order; i++)
                rhs.coeff[i] = a[i];
                
        return in;
}

