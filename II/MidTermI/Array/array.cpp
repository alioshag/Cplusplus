/*******************************************************************
filename: "array.cpp" Midterm#3
author: Aliosha Gonzalez
synopsis: This is the implementation of the class Array. The definition file is
        "array.h"
*************************************************************************/
#include "array.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Array::Array() : itsSize(10)    //init with size of 10.
{
        pType = new int[itsSize];
        cout << "Default CC Array[10]\n";
}
Array::Array(int Size) : itsSize(Size)//creates array with size
{
        pType = new int[itsSize];
        cout << "One int arg CC Array\n";
}
Array::Array(int Size, int Value) : itsSize(Size) //init array with size and values
{
        cout << "Two int arg CC of Array\n";
        
        pType = new int[itsSize];
        for (int i = 0; i < itsSize; i++)
                pType[i] = Value;
}
Array::~Array()
{
        delete [] pType;
        cout << " Default Destructor array\n";
}
Array::Array(const Array& rhs)     //copy CC makes a deep copy b/c of use of pointers and dynamically allocated data
        :itsSize(rhs.getSize())
{
        pType = new int[itsSize];
        for (int i = 0; i < itsSize; i++)
                pType[i] = rhs.pType[i];
}
//operators
Array& Array::operator=(const Array &rhs)
//assignment operator makes a deep copy instead of shallow copy b/c the 
//use of pointers and dynamically allocated variables
{
        if (this == &rhs)   //test if the rhs is the same as lhs
        {
                return *this;
        }
        delete [] pType;
        itsSize = rhs.getSize();    //get the size of the rhs operand
        pType = new int[itsSize];  //size from the rhs operand
        
        for (int i = 0; i < itsSize; i++)
                pType[i] = rhs.pType[i];
        
        return *this;
}
int& Array::operator[](int offSet)    //l-value invocation
{
        if (offSet < 0 || offSet >= itsSize)
        {
                cerr << "Illegal index in array\n";
                exit(1);
        }

        return pType[offSet];
}
const int& Array::operator[](int offSet)const   //r-value invocation
{
        if (offSet < 0 || offSet >= itsSize)
        {
                cerr << "Illegal Index in Arra\n";
                exit(1);
        }

        return pType[offSet];
}
//accessor
int Array::getSize()const{ return itsSize;}//could be done at interface
//mutator
void Array::setResize(int newSize)  //resize array, new array will mirror the old values
{
        int smallS;
        if (itsSize < newSize)
        {
                smallS = itsSize;
        }else
        {
                smallS = newSize;
        }
        itsSize = newSize;
        int *newA;
        newA = new int[newSize];  
        for (int i = 0; i < smallS;i ++) //temp array with new size, catch old values allow by its own newsize
                newA[i] = pType[i];
        
        delete [] pType;
        pType = new int[newSize];
        for (int i = 0; i < newSize; i++) //copy temp to pType
        {
                pType[i] = newA[i];
        }

        delete [] newA;   //restore memory from tempA
}
void Array::decimate(int df)   //decimator_factor
{
        if (df <= 0 && df >= itsSize)  //check for illegal decimator factor
        {
                cerr << "Illegal decimator factor\n";
                exit(1);
        }

        int div = itsSize / df;   //quantity of nth values affected by the factor
        int *tempA = new int[itsSize-div];  //temp with newsize=oldsize-div 
        int tempA_i = 0;             //index for the new array
        for (int i = 0; i < itsSize; i++)
        {
                if ((i+1) % df != 0)
                {
                        if (tempA_i < (itsSize-div))  //if index of tempA < tempA size
                        {
                                /*cout << "i="<<i<<"  A_i="<< tempA_i
                                        << "  tempA[tempA_i]= " << tempA[tempA_i] 
                                        << "  pType[i]=" << pType[i] << endl;
                                */
                                tempA[tempA_i++] = pType[i];
                                /*
                                cout << "  A_i++="<< tempA_i-1<< "  tempA[tempA_i]= " << tempA[tempA_i-1] << endl;
                                */
                        }
                }
                
        }

        delete [] pType;
        itsSize = itsSize-div;
        pType = new int[itsSize];
        for (int i = 0; i< itsSize; i++)
        {                
                pType[i] = tempA[i];//cout << "pType[" << i << "]=" << pType[i] << endl;
        }

        delete [] tempA;
}
void Array::interpolate(int ifactor)  //interpolator_factor, 
{
        if (ifactor < 2)
        {
                cout << "Illegal operation. ifactor can't be lower than 2\n";
                exit(1);
        }
        int newSize;  //newSize after the interpolation
        if (itsSize % (ifactor-1) == 0)
        {       //if reminder = 0, the last insertion endup out of the array
                newSize = itsSize + itsSize /(ifactor-1) - 1;
        }else 
        {       //if reminder !=0, the last insertion endup inside the array
                newSize = itsSize + itsSize / (ifactor-1); 
        }
        //build the interpolate array on tempA
        int *tempA = new int[newSize];
        int tempA_i = 0;   //index for tempA
        
        int p_i = 0; //index of old array
        for (int i=0; i < newSize; i++)   //loop through new array while building it
        {
                if ((i+1) % ifactor != 0)    //i+1 corrects for i begining at zero
                {
                        tempA[i] = pType[p_i++];    //reminder zero assign value from old array, p_i++ after
                }else
                {
                        tempA[i] = 0;      //adds zero when reminder is zero
                }
        }
        
        //copy tempA to pType
        itsSize = newSize;
        delete [] pType;
        pType = new int[newSize];
        for (int i = 0; i < newSize; i++)
        {
                pType[i] = tempA[i];
        }
}
ostream& operator<<(ostream& out, const Array& rhs)
{
        for (int i = 0; i < rhs.itsSize;i++)
                cout << "value [" << i << "]= " << rhs.pType[i] << "\n";

        return out;
}
