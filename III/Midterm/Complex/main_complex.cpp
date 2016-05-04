/***************************************************************
 * filename: "main_complex.cpp"
 * author: Aliosha Gonzalez 
 * synopsis: This is a test file for the class Complex.
 * ***************************************************************/
#include <iostream>
#include <cstdlib>
#include "complex.h"
using namespace std;

int main()
{
        Complex C1(3,4), C2(6,8), C3;

        C3=C1+C2;
        cout << "C3= C1 + C2 --> " << C3 << endl;
        C3=C2-C1;
        cout << "C3= C2 - C1 --> " << C3 << endl;
        C3=C2*C1;
        cout << "C3= C2 * C1 --> " << C3 << endl;
        C3=C2 / C3;
        cout << "C3= C2 / C1 --> " << C3 << endl;
        
        C2+=C1;
        cout << "C2 += C1    --> " << C2 << endl;
        C2-=C1;
        cout << "C2 -= C1    --> " << C2 << endl;
        
        bool I = (C2 == C1);
        cout << " --> 0-false and 1-true" << endl;
        cout << "bool I = (C2 == C1) = " << (I) << endl
        I = (C2 != C1);
        cout << "bool I = (C2 != C1) = " << (I) << endl;
        
        int real = C2.getReal();
        cout << "int real = C2.getReal() --> " << real << endl;
        int imag = C2.getImag();
        cout << "int imag = C2.getImag() --> " << imag << endl;
        
        return(0);
}
