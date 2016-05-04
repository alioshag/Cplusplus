/***********************************************************
filename: "main.cpp"
author: Aliosha Gonzalez
synopsis: This is the test file for the base class Poly.
***********************************************************/
          
#include <iostream>
#include "template_poly.h"
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
        Poly<int> P;

        
        double a1[] = {-38.0,2.0,-24.0,6.0,4.0};
        int size_a1 = sizeof a1 / sizeof a1[0];
        Poly<double> P1(size_a1 - 1, a1);
        cout << "P1: " << P1 << endl;
        
        double a2[] = {-38.0,2.0,-14.0,0.0,0.0,10.0,0.0,4.0};
        int size_a2 = sizeof a2 / sizeof a2[0];
        Poly<double> P2(size_a2 - 1, a2);    //Poly::Poly(int Order, int *Coeff)
        cout << "P2: " << P2 << endl;

        Poly<double> P3 = P1 + P2;
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
        double Z = P3(X);
        cout << "Z = P3(int X = 5) --> " << Z << endl;
        
        return EXIT_SUCCESS;
}
