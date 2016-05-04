/**********************************************************************
filename: date-test.cpp
author: Aliohsa Gonzalez
description: This is the test program for the class Date.
             The interface of the class Date is on the file "date.h" 
             and the implementation is on the file "date.cpp"
 *
 * ****************************************************************************/
#include "date.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
        Date D1; cout << D1 << endl;
        Date D2( 07, 25, 2013); cout << D2 << endl;
        Date D3( 02, 29, 2000); cout << D3 << endl;
        Date D4( 02, 28, 1986); cout << D4 << endl;
        
        D4.setdate();
        cout << "New D4 =" << D4 << endl;
        
        D4 = D1;
        cout << "D4 = D1 --> D4= " << D4 << endl;

        cout << "D1.DobDays() =" << D1.DobDays() << endl;
        cout << "D2.DobDays() =" << D2.DobDays() << endl;
        
        cout << "D1=" << D1 << endl;
        cout << "D2=" << D2 << endl;
        
        int i = D1+D2;
        cout << "D1+D2= i= " << i << endl;
        i = D2 - D1;
        cout << "D2-D1= i= " << i << endl;

        

        
        return 0;
}
