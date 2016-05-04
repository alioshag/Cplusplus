/******************************************
filename: test-poly.cpp   Midterm#1
author: aliosha gonzalez
synopsis: This is a test program for the class Poly
*****************************************/
#include "poly.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
        typedef int* IntPtr;
        IntPtr ptr1, ptr2;

        int a1[] = {-19, 1, -12, 3, 2};
        ptr1 = a1;
        Poly P1( 4, ptr1);
        cout << "P1= " << P1 << endl;
        
        int a2[] = {-19, 1, -6, 0, 0, 7, 0, 2};
        ptr2 = a2;
        Poly P2( 7, ptr2);
        cout << "P2= " << P2 << endl;

        Poly P3;
        P3=P1+P2;cout << "P3=P1+P2 --> " << P3 << endl; 
        P3=P2-P1;cout << "P3=P2-P1 --> " << P3 << endl; 
        P3=P1*10;cout << "P3=P1*10 --> " << P3 << endl; 
        P3=P1*P2;cout << "P3=P1*P2 --> " << P3 << endl; 
        
        bool flag = (P1==P2);cout << "bool flag = (P1==P2) =";
        if (flag == 0)
        {
                cout << " FALSE\n";
        }
        else{
                cout << " TRUE\n";
        }
        
        P1[3] = P2[5];
        cout << "P1[3]=P2[5]   P1[3]=" << P1[3] << endl;

        int Z = P3(3);
        cout <<  "int Z=P3(3) --> Z=" << Z << endl;

        return 0; 
}
