/******************************************************
filename: "poly.cpp"
author: Aliosha Gonzalez
synopsis: This is the implementation file for the base class Poly. 
The interface is on the file "poly.h"
******************************************************/
#include <iostream>
#include <cstdlib>
#include "poly.h"
//#define _DEBUG
using namespace std;

Poly::Poly() : order(0), size(1)
{
#ifdef _DEBUG
        cout << "Default Constructor\n";
#endif        
        coeff = new int[0];
        if (coeff == NULL) 
        {
               cerr << "Error allocation memory\n";
               exit(EXIT_FAILURE);
        }
        coeff[0] = 1;
}
Poly::Poly(int Order, int Default) : order(Order), size(Order+1)
{
#ifdef _DEBUG
        cout << "Init Constructor \n";
#endif
        coeff = new int[size];                //test to NULL ****************
        if (coeff == NULL) 
        {
               cerr << "Error allocation memory\n";
               exit(EXIT_FAILURE);
        }
        
        for (int i = 0; i < size;i++)
                coeff[i] = Default;
}           
Poly::Poly(int Order, int* Coeff): order(Order), size(Order+1) 
{
#ifdef _DEBUG
        cout << "Parameterized Constructor\n";
#endif        
        coeff = new int[size];
        if (coeff == NULL) 
        {
               cerr << "Error allocation memory\n";
               exit(EXIT_FAILURE);
        }

        for (int i = 0; i < size; i++)
                coeff[i] = Coeff[i];
}
Poly::Poly(const Poly& p) : order(p.order), size(p.order+1)
{
        cout << "Copy Constructor\n";
        coeff = new int[size];
        if (coeff == NULL) 
        {
               cerr << "Error allocation memory\n";
               exit(EXIT_FAILURE);
        }

        for (int i=0; i < size; i++)
                coeff[i] = p.coeff[i];
}
Poly::~Poly()
{
#ifdef _DEBUG
        cout << "Destructor\n";
#endif
        delete [] coeff;
}
//mutators
//query user for coeffients values, the size remains the same
void Poly::set()    
{
     cout << "Please enter the coeff of the polinomio\n";
     int n;
     for (int i=0; i < size; i++)
     {
             cout << "Enter coeff with order " << order-i << ": ";
             cin >> n; 
             coeff[order-i] = n;
     }    
} 
//takes coeff values from an array provided as an argument
//the size may change, the memory on the heap of the object is freeed and new memory is requested   
void Poly::set(int Coeff[], int theSize)
{
        delete [] coeff;
        order = theSize - 1;
        size = theSize;
        coeff = new int[size];
        if (coeff == NULL)    //test dymanic memory allocation
        {
               cerr << "Error allocation memory\n";
               exit(EXIT_FAILURE);
        }
        for (int i=0; i < size; i++)
        {
               coeff[i] = Coeff[i]; 
               cout << "coeff[" << i << "]= " << coeff[i] << endl;
        }
}     
//accessor
int* Poly::get(int* coeff_external)
{
        for (int i=0; i < size; i++)
                coeff_external[i] = coeff[i];

        return coeff_external;
}

//overloaded operators
const Poly Poly::operator+(const Poly &rhs) const
{
        int bigSize, smallSize;
        int *bigCoeff, *smallCoeff;
       
        if (size > rhs.size) 
        {
                bigSize = size;
                smallSize = rhs.size;
                bigCoeff = coeff;
                smallCoeff = rhs.coeff;
        }else
        {
                bigSize = rhs.size;
                smallSize = size;
                bigCoeff = rhs.coeff;
                smallCoeff = coeff;
        }
        //create temp_A local array with coeff of higher order poly
        int temp_A[bigSize];  //local variable array
        for (int i=0; i < bigSize; i++)
                temp_A[i] = bigCoeff[i];
        
        //adds smaller poly to big poly
        for (int i=0; i < smallSize; i++)
                temp_A[i] += smallCoeff[i];
        
        return Poly(bigSize-1, temp_A);  //temp_A ends here
}
const Poly Poly::operator-(const Poly &rhs) const
{
        //create temp_A with negative coeff of rhs poly
        int temp_A[rhs.size];    //local array

        for (int i=0; i < rhs.size; i++)
                temp_A[i] = (-rhs.coeff[i]);
        
        return *this + Poly(rhs.order, temp_A);
}
//scale the coeff of the poly
const Poly Poly::operator*(const int scale)const
{
        int temp_A[size];   //local var

        for (int i = 0; i < size; i++)
                temp_A[i] = coeff[i] * scale;

        return Poly(order, temp_A);  
        
}
const Poly Poly::operator*(const Poly &rhs)const
{
        //size of end poly is the sum of the order of each poly + 1
        int temp_order = order + rhs.order;
        int temp_A[temp_order + 1];  //size = order + 1
        fill_n(temp_A, temp_order+1, 0);
        
        for (int i=0; i < size; i++)
        {
                for (int j=0; j < rhs.size; j++)
                {
                        temp_A[i + j] += coeff[i] * rhs.coeff[j];
                }
        }
        return Poly(temp_order, temp_A);
}
const bool Poly::operator==(const Poly &rhs)const
{
        if (order != rhs.order || size != rhs.size)
                return false;

        for (int i=0; i < size; i++)
                if (coeff[i] != rhs.coeff[i]) return false;
#ifdef _DEBUG
        cout << "final" << endl;
#endif
        return true;
}
const int Poly::operator[](const int I) const  //returns coeff value
{
        if (I<0 || I>size)
        {
                cerr << "Program Abort!" << " Illegal index array." << endl;
                exit(EXIT_FAILURE);
        }

        return coeff[I];
}
int& Poly::operator[](int I) //return coeff address, ok for lvalue on assigment operator
{
        if (I<0 || I>size)
        {
                cerr << "Program Abort!" << " Illegal index array." << endl;
                exit(EXIT_FAILURE);
        }

        return coeff[I];
}
//Horner's Method
const int Poly::operator()(int X)const
{
        int total = 0;

        for (int i=0; i < size; i++)
        {
                total = total * X + coeff[order-i];
        }
        
        return total;
}
Poly& Poly::operator=(const Poly& rhs)
{
        if (this == &rhs)
               return *this;
                
        order = rhs.order;
        size = rhs.size;
        delete [] coeff;
        coeff = new int[size];
        if (coeff == NULL) 
                {
                        cerr << "Error allocation memory\n";
                        exit(EXIT_FAILURE);
                }
                
        for (int i = 0; i < size; i++)
                coeff[i] = rhs.coeff[i];
                       
        return *this;
}      
ostream& operator<<(ostream& Out, const Poly& rhs)
{
        for (int i = 0; i < rhs.size; i++)
        {
               if (rhs.coeff[rhs.order-i] != 0) 
                              {
                              if (rhs.coeff[rhs.order-i] > 0) Out << '+';
                              Out << rhs.coeff[rhs.order-i];
                              if (rhs.order-i > 0) Out << 'X';
                              if (rhs.order-i > 1) Out << '^' << rhs.order-i;
                              }
       }
       return Out;
}
