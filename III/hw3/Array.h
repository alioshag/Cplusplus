/***********************************************************
 * filename: "Array.h"
 * author: Aliosha Gonzalez
 * synopsis: boiler plate for an "ArrayTemplate.cpp" 
 * ***********************************************************/
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <cstdlib>
using namespace std;

class Array
{
        public:
                Array(): size(50) {
                        A = new int[size]; cout << "Default Constructor\n";
                }
                Array(int theSize): size(theSize){
                        A = new int[size]; cout << "Parameterized Constructor\n";
                }
                Array(const Array& aObj): size(aObj.size){
                        A = new int[size];cout << "Copy Constructor\n";
                        for (int i = 0 ; i < size; i++)
                                A[i] = aObj.A[i];
                }
                ~Array() {delete [] A;cout << "Destructor\n";}                     
               //accesors
               int getSize() const {return size;}
               //operator
               int& operator[] (int index) {cout << "operator[]\n";
                       if (index >= 0 || index < size){
                               return A[index];}
                       else {
                               cerr << "Illegal index\n";
                               exit(1);
                       }
               }
               Array& operator=(const Array& rhs) {cout << "operator=\n";
                       if (this == &rhs) return *this;//both objects in both sides
                       
                       if (size != rhs.size) {  //incase objects have diff sizes
                               delete [] A;
                               A = new int[rhs.size];
                               size = rhs.size;    
                       }
                       for (int i=0;i < size;i++)
                               A[i] = rhs.A[i];
                       
                       return *this;               
               }
               //const Array& operator=(int index) const;
               friend ostream& operator <<(ostream& out, const Array& rhs){
                       for (int i=0; i < rhs.size; i++)
                               out << i <<  "-> " << rhs.A[i] << endl; 
                       return out;
               }
               friend istream& operator >>(istream& in, Array& rhs){
                       int inputN;
                       for (int i=0; i < rhs.size;i++) {
                               in >> inputN;
                               rhs.A[i]= inputN;
                       }
                       return in;
               }
                       
        private:
                int* A;
                int size;
};

#endif
