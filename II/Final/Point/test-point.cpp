/***********************************************************************
filaname: "testpoint.cpp", final#1
author: Aliosha Gonzalez
synopsis: This file test the class Point.  

************************************************************************/
#include "pointtemplate.h"
#include "pointtemplate.cpp"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
       Point<double> P1(1.0,1.5), P2(2.2,3.3);
       cout << "P1-->" << P1 << endl;
       cout << "P2-->" << P2 << endl;
       
       cout << "P1 = P2\n";
       P1 = P2;
       cout << "P1-->" << P1 << endl;
       
       cout << "P1.reset_location(5,5)\n";
       P1.reset_location(5.5,5.5);
       cout << "P1-->" << P1 << endl;

       P1 + 3;
       cout << "P1+3-->" << P1 << endl;

       cout << "P1-P2 distance -->" << P1-P2 << endl;




       
        //cin.get();
        return 0;
}
