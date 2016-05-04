/***********************************************************
filename: "poly.h"
author: Aliosha Gonzalez
synopsis: This is the interface file for the class Poly. The implementation
          will be on the file "poly.cpp"
***********************************************************/
#ifndef TEMPLATE_POLY_H
#define TEMPLATE_POLY_H

#include <iostream>
#include <cstdlib>
using namespace std;

template<class T>
class Poly 
{
        public:
                Poly();                           //ok default constructor- order=0 & coeff[0]=1
                Poly(int Order, T Default = 0); //ok creates Nth order poly and inits all coeffs
                Poly(int Order, T *Coeff);      //ok creates an Nth polynomial & inits
                Poly(const Poly<T>& p);              //ok Copy Constructor
                ~Poly();                          //ok destructor
                //mutators 
                void set();                       //ok Query user for coeff values)
                void set(T coeff[], int size);  //ok
                //accessors
                int getOrder() const{return order;} //ok get order of polynomial
                T* get(T* coeff_external)const; //ok copies poly coeff values to external array
                //overloaded operators
                const Poly operator+(const Poly<T> &rhs) const;//ok add two polynomials
                const Poly operator-(const Poly<T> &rhs) const;//ok subt two polynomials
                const Poly operator*(const int scale)const;//*****ok scale Poly(maybe template)*****
                const Poly operator*(const Poly<T> &rhs)const; //ok mult two polynomials
                const bool operator==(const Poly<T> &rhs)const;//ok equality operator
                const T operator[](const int I)const;     //ok returns the Ith coeff
                T& operator[](int I);            //ok assign int into lvalue[] operand
                const T operator()(T X)const;  //ok evaluate P(x) accordinly
                Poly& operator=(const Poly<T> &rhs);  //ok assigment operator
                //friends functions
                friend Poly<T> operator*(int lhs, Poly<T>& rhs){return rhs*lhs;}
                friend ostream& operator<<(ostream &Out, const Poly<T> &rhs)//ok
                {
                        for (int i = 0; i < rhs.size; i++)
                        {
                                if (rhs.coeff[rhs.order-i] != 0)  //begins in coeff with higher order
                                        {
                                        if (rhs.coeff[rhs.order-i] > 0) Out << '+';
                                        Out << rhs.coeff[rhs.order-i];
                                        if (rhs.order-i > 0) Out << 'X';
                                        if (rhs.order-i > 1) Out << '^' << rhs.order-i;
                                        }
               }
               return Out;
               }
        private:
               int order;    //order of the polinomial
               int size;     //order+1
               T* coeff;    //pointer to array of coeff on the heap
};
template<class T>
Poly<T>::Poly() : order(0), size(1)
{
#ifdef _DEBUG
        cout << "Default Constructor\n";
#endif
        coeff = new T[0];
        if (coeff == NULL)
        {
                cerr << "Error allocation memory\n";
                exit(EXIT_FAILURE);
        }
        coeff[0] = 1;
}
template<class T>
Poly<T>::Poly(int Order, T Default) : order(Order), size(Order+1)
{
#ifdef _DEBUG
        cout << "Init Constructor \n";
#endif
        coeff = new T[size];                //test to NULL ****************
        if (coeff == NULL)
                {
                        cerr << "Error allocation memory\n";
                        exit(EXIT_FAILURE);
                }

        for (int i = 0; i < size;i++)
                coeff[i] = Default;
}
template<class T>
Poly<T>::Poly(int Order, T* Coeff): order(Order), size(Order+1)
{
#ifdef _DEBUG
        cout << "Parameterized Constructor\n";
#endif
        coeff = new T[size];
        if (coeff == NULL)
                {
                       cerr << "Error allocation memory\n";
                       exit(EXIT_FAILURE);
                }
        for (int i = 0; i < size; i++)
                coeff[i] = Coeff[i];
}
template<class T>
Poly<T>::Poly(const Poly<T>& p) : order(p.order), size(p.order+1)
{
        cout << "Copy Constructor\n";
        coeff = new T[size];
        if (coeff == NULL)
                {
                      cerr << "Error allocation memory\n";
                      exit(EXIT_FAILURE);
                }
        for (int i=0; i < size; i++)
                coeff[i] = p.coeff[i];
}
template<class T>
Poly<T>::~Poly()
{
#ifdef _DEBUG
        cout << "Destructor\n";
#endif
        delete [] coeff;
}
template<class T>
void Poly<T>::set()
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
////the size may change, the memory on the heap of the object is freeed and new memory is requested
template<class T>
void Poly<T>::set(T Coeff[], int theSize)
{
        delete [] coeff;
        order = theSize - 1;
        size = theSize;
        coeff = new T[size];
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
template<class T>
T* Poly<T>::get(T* coeff_external)const
{
                for (int i=0; i < size; i++)
                                        coeff_external[i] = coeff[i];

                        return coeff_external;
}

//overloaded operators
template<class T>
const Poly<T> Poly<T>::operator+(const Poly<T> &rhs) const
{
        int bigSize, smallSize;
        T *bigCoeff, *smallCoeff;

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
        T temp_A[bigSize];  //local variable array
        for (int i=0; i < bigSize; i++)
                temp_A[i] = bigCoeff[i];

//adds smaller poly to big poly
        for (int i=0; i < smallSize; i++)
                temp_A[i] += smallCoeff[i];

        return Poly<T>(bigSize-1, temp_A);  //temp_A ends here
}
template<class T>
const Poly<T> Poly<T>::operator-(const Poly<T> &rhs) const
{
//create temp_A with negative coeff of rhs poly
        T temp_A[rhs.size];    //local array

        for (int i=0; i < rhs.size; i++)
                temp_A[i] = (-rhs.coeff[i]);

        return *this + Poly<T>(rhs.order, temp_A);
}
//scale the coeff of the poly
template<class T>
const Poly<T> Poly<T>::operator*(const int scale)const
{
        T temp_A[size];   //local var
                                                        
        for (int i = 0; i < size; i++)
                temp_A[i] = coeff[i] * scale;

        return Poly<T>(order, temp_A);
}
template<class T>
const Poly<T> Poly<T>::operator*(const Poly<T> &rhs)const
{
//size of end poly is the sum of the order of each poly + 1
       int temp_order = order + rhs.order;
       T temp_A[temp_order + 1];  //size = order + 1
       fill_n(temp_A, temp_order+1, 0);

       for (int i=0; i < size; i++)
       {
               for (int j=0; j < rhs.size; j++)
               {
                       temp_A[i + j] += coeff[i] * rhs.coeff[j];
               }
       }
       
       return Poly<T>(temp_order, temp_A);
}
template<class T>
const bool Poly<T>::operator==(const Poly<T> &rhs)const
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
template<class T>
const T Poly<T>::operator[](const int I) const  //returns coeff value
{
       if (I<0 || I>size)
       {
              cerr << "Program Abort!" << " Illegal index array." << endl;
              exit(EXIT_FAILURE);
       }
       return coeff[I];
}
template<class T>
T& Poly<T>::operator[](int I) //return coeff address, ok for lvalue on assigment operator
{
      if (I<0 || I>size)
      {
              cerr << "Program Abort!" << " Illegal index array." << endl;
              exit(EXIT_FAILURE);
      }
      return coeff[I];
}
//Horner's Method
template<class T>
const T Poly<T>::operator()(T X)const
{
        T total = 0;

        for (int i=0; i < size; i++)
                  total = total * X + coeff[order-i];
                  

        return total;
}
template<class T>
Poly<T>& Poly<T>::operator=(const Poly<T> &rhs)
{
        if (this == &rhs)
        {
                return *this;
        }else {
                order = rhs.order;
                size = rhs.size;
                delete [] coeff;
                coeff = new T[size];
                if (coeff == NULL)
                {
                        cerr << "Error allocation memory\n";
                        exit(EXIT_FAILURE);
                }

                for (int i = 0; i < size; i++)
                        coeff[i] = rhs.coeff[i];
        }

        return *this;
}
#endif  //POLY_H
