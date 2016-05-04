/***************************************************
filename: "test-array.cpp" Midterm#3
author: Aliosha Gonzalez
synopsis: Test file for the class Array. 
          The interface is on the file "array.h"
          The implementation is on the file "array.cpp"
**************************************************************/

#include "array.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
        Array A1;
        cout << "Testing A1\n" << A1 << endl;

        Array A2(5);
        cout << "Testing A2(5)\n" << A2 << endl;
        
        Array A3(10, -1000);
        cout << "Testing A3(10, -1000)\n" << A3 << endl;

        A1 = A3;
        cout << "Testing A1=A3. A1 values are\n" << A1 << endl;

        A1[0] = 3;
        cout << "Testing A1[0]=3.  A1[0]="  << A1[0] << endl;

        int i = A1[0];
        cout << "Testing i = A1[0]." << " i= " << i << endl;

        cout << "Testing A1.getSize()= " << A1.getSize() << endl;
        
        A1.setResize(10);
        cout << "Testing A1.setResize(10). A1 values are=\n" <<  A1 << endl;

        A1[0]=1;
        A1[1]=2;
        A1[2]=3;
        A1[3]=4;
        A1[4]=5;
        A1[5]=6;
        A1[6]=7;
        A1[7]=8;
        A1[8]=9;
        A1[9]=10;
        cout << "Testing assigning values A1[0]=1, A1[1]=2...A1[9]=10\n" << A1 << endl;


        A1.decimate(3);
        cout << "Testing A1.decimate(3)\n" << A1 << endl;

        A1.interpolate(3);
        cout << "Testing A1.interpolate(3)\n" << A1 << endl;

        return 0;
}
