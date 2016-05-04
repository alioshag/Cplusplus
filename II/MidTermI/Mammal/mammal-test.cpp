/*********************************************************************
filename:mammal-test.cpp   Midterm#2
author: Aliosha Gonzalez
description: This is a test program for the class Mammal.
             The interface of the class Mammal is on the file "mammal.h"
             and the implementation is on the file "mammal.cpp"
 *
 * ********************************************************************/
#include "mammal.h"
#include "cat.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void ChangeWeight(Mammal &X){X.setWeight();}

int main()
{
        
        Mammal M1(110), M2(220);
        cout << "Testing M1(110).\n" << M1 << endl;
        cout << "Testing M2(220).\n" << M2 << endl;

        cout << "Testing M1.getWeight() of M1 and M2 is: " 
                << M1.getWeight() << "  " 
                << M2.getWeight() << endl;
        cout << "Testing M1.getId() M1 and M2 is: " 
                << M1.getId() << " " 
                << M2.getId() << endl;
        
        cout << "Testing M1.setDOB()\n"; M1.setDOB();
        cout << "Testing M1.setWeight()\n"; M1.setWeight();
        cout << M1 << endl;

        Mammal M3(110, Date(7, 25, 2013));
        cout << "Testing M3(100, Date(7,25,2013))\n " << M3 << endl;

        Cat C1("Afghan", 3, 220, Date(3, 5, 2000));
        cout << "C1('Afghan', 3, 220, Date(3, 5, 2000))\n" << C1 << endl;

        cout << "Instantiating three cats.\n";

        Cat a[3] = 
        {
                Cat("Afghan" , 2, 110, Date(1, 1, 2000)), 
                Cat("Persian", 3, 220, Date(2, 2, 2002)),
                Cat("Cuban"  , 4, 330, Date(6, 3, 2013))
        };

        for (int i = 0; i<=2; i++)         //printing the obj on array
                cout  << a[i] << endl;
       
        ChangeWeight(M1);      //global function
        cout << "Testing global function ChangeWeighting(M1).\n" << M1 << endl;//global function

        cout << "Testing print number of Mammals created\n" << CountMammal() << endl;
        
        return 0;
}

