/*****************************************************************
 * filename: "ArrayTemplate.cpp"
 * author: Aliosha Gonzalez
 * synopsis: This is a template file for an array. 
 * **************************************************************/
#ifndef ARRAYTEMPLATE_H
#define ARRAYTEMPLATE_H
#include <iostream>
#include <cstdlib>
using namespace std;

template<class T>
class Array
{
        public:
                Array(): size(10){cout << "Default Constructor\n";ptrA = new T[size];}
                Array(int theSize)
                        :size(theSize){cout << "Parameterized Constructor\n";ptrA = new T[size];}
                Array(const Array<T>& rhs): size(rhs.size) {
                        cout << "Copy Constructor\n";
                        ptrA = new T[size];
                        for (int i(0);i < size; i++) 
                                ptrA[i] = rhs.ptrA[i];
                }
                ~Array() {cout << "Destructor\n"; delete [] ptrA;}
                //accessors
                int getSize() const {return size;}
                //operator
                T& operator[](int index){
                        //cout << "operator[]\n";
                        if (index >=0 || index < size){
                                return ptrA[index];
                        }else {
                                cerr << "Illegal index\n";
                                exit(1);
                        }
                }
               Array<T>& operator=(const Array<T>& rhs) {
                       //cout << "operator=\n";
                       if (this == &rhs) return *this; //both objects are equal

                       if (size != rhs.size) {
                               delete [] ptrA;
                               ptrA = new T[rhs.size];
                               size = rhs.size;
                       }
                       for (int i(0); i < size;i++)
                               ptrA[i] = rhs.ptrA[i];

                       return *this;
               }
               //friends functions
               template<class U>
               friend ostream& operator <<(ostream& out, const Array<U>& rhs) {
                       for (int i(0); i < rhs.size; i++)
                               out << rhs.ptrA[i] << endl;
                       return out;
               }
               template<class U>
               friend istream& operator >>(istream& in, Array<U>& rhs){
                       U input;
                       for (int i(0); i < rhs.size;i++) {
                               in >> input;
                               rhs.ptrA[i]= input;
                       }
                       return in;
               }
               
        private:
                T* ptrA;
                int size;
};
#endif //ARRAYTEMPLATE_H 

