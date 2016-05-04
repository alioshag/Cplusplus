/***********************************************************
filename: "main.cpp"
author: Aliosha Gonzalez
synopsis: This is the test file for the base class Poly.
***********************************************************/
          
#include "poly.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
        int Coeff1[] = {-38,2,-24,6,4};
        Poly P1((sizeof Coeff1 / sizeof Coeff1[0] - 1), Coeff1);
        cout << "P1: " << P1 << endl;
        
        int Coeff2[] = {-38,2,-14,0,0,10,0,4};
        Poly P2(sizeof Coeff2 / sizeof Coeff2[0] - 1, Coeff2);    //Poly::Poly(int Order, int *Coeff)
        cout << "P2: " << P2 << endl;
        
        Poly P3 = P1 + P2;
        cout << "P3 = P1 + P2 --> " << P3 << endl;
        
        P3 = P2 - P1;
        cout << "P3 = P2 - P1 --> " << P3 << endl;

        P3 = P1 * 10;
        cout << "P3 = P1 * 10 --> " << P3 << endl;

        P3 = 10 * P1;
        cout << "P3 = 10 * P1 --> " << P3 << endl;
        
        P3 = P1 * P2;
        cout << "P3 = P1 * P2 --> " << P3 << endl;
        
        bool flag = (P1==P2);
        cout << "flag = (P1 == P2) --> ";
        if (flag) 
        {
                cout << " true\n";
        }
        else cout << " false\n";

        P1[3] = P2[5];
        cout << "P1[3] = P2[5] --> " << P1[3] << endl;

        //int Z = P3((int X=5));  //didnt work --> parse error before '=' token
        int X=5;
        int Z = P3(X);
        cout << "int Z = P3(int X = 5) --> " << Z << endl;
        
        return EXIT_SUCCESS;
}
