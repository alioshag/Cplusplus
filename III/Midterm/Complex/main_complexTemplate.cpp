/***************************************************************
 * filename: "main_complexTemplate.cpp"
 * author: Aliosha Gonzalez 
 * synopsis: This is a test file for the class Complex.
 * ***************************************************************/
#include <iostream>
#include <cstdlib>

#include "complexTemplate.h"
using namespace std;
int main()
{
        Complex<int> C1(3,4), C2(6,8), C3;

        C3=C1+C2;
        cout << "C3= C1 + C2 --> " << C3 << endl;
        C3=C2-C1;
        cout << "C3= C2 - C1 --> " << C3 << endl;
        C3=C2*C1;
        cout << "C3= C2 * C1 --> " << C3 << endl;
        C3=C2/ C1;
        cout << "C3= C2 / C1 --> " << C3 << endl;
        
        C2+=C1;
        cout << "C2 += C1    --> " << C2 << endl;
        C2-=C1;
        cout << "C2 -= C1    --> " << C2 << endl;
        
        bool I = (C2 == C1);
        cout << "0 false, 1 true \n";
        cout << "bool I = (C2 == C1) --> " << (I) << endl;
        I = (C2 != C1);
        cout << "bool I = (C2 != C1) --> " << (I) << endl;
        
        int real = C2.getReal();
        cout << "int real = C2.getReal() --> " << real << endl;
        int imag = C2.getImag();
        cout << "int imag = C2.getImag() --> " << imag << endl << endl;;
          
        Complex<float> F1(3.0,4.0), F2(6.0,8.0), F3;

        F3=F1+F2;
        cout << "F3= F1 + F2 --> " << F3 << endl;
        F3=F2-F1;
        cout << "F3= F2 - F1 --> " << F3 << endl;
        F3=F2*F1;
        cout << "F3= F2 * F1 --> " << F3 << endl;
        F3=F2/F1;
        cout << "F3= F2 / F1 --> " << F3 << endl;
        
        F2+=F1;
        cout << "F2 += F1    --> " << F2 << endl;
        F2-=F1;
        cout << "F2 -= F1    --> " << F2 << endl;
        
        bool J = (F2 == F1);
        cout << "0 false, 1 true \n";
        cout << "bool J = (F2 == F1) --> " << (J) << endl;
        J = (F2 != F1);
        cout << "bool J = (F2 != F1) --> " << (J) << endl;
        
        float real2 = F2.getReal();
        cout << "float real = F2.getReal() --> " << real2 << endl;
        float imag2 = F2.getImag();
        cout << "float imag = F2.getImag() --> " << imag2 << endl << endl;;


        Complex<double> D1(3.0,4.0), D2(6.0,8.0), D3;

        D3=D1+D2;
        cout << "D3= D1 + D2 --> " << D3 << endl;
        D3=D2-D1;
        cout << "D3= D2 - D1 --> " << D3 << endl;
        D3=D2*D1;
        cout << "D3= D2 * D1 --> " << D3 << endl;
        D3=D2/D1;
        cout << "D3= D2 / D1 --> " << D3 << endl;
        
        D2+=D1;
        cout << "D2 += D1    --> " << D2 << endl;
        D2-=D1;
        cout << "D2 -= D1    --> " << D2 << endl;
        
        I = (D2 == D1);
        cout << "0 false, 1 true \n";
        cout << "bool I = (D2 == D1) --> " << (I) << endl;
        I = (D2 != D1);
        cout << "bool I = (D2 != D1) --> " << (I) << endl;
        
        double real3 = D2.getReal();
        cout << "double real = D2.getReal() --> " << real3 << endl;
        double imag3 = D2.getImag();
        cout << "double imag = D2.getImag() --> " << imag3 << endl << endl;

        Complex<char> H('a', 5);
        cout << "The encrypted char is " << H.getChar() << endl;
        char unencrypted = H ^ 5;
        cout << "The unencrypted char is " << unencrypted << endl;
        
        return(0);
}
