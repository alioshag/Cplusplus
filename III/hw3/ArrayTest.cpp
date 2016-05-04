/**********************************************
 * filename: "ArrayTest.cpp"
 * author : Aliosha Gonzalez
 * synopsis: Test file for "Array.h"
 * *******************************************/
#include "Array.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
        Array A1(10);

        for (int i = 0; i < A1.getSize(); i++)
        {
                A1[i] = i;
        }

        cout << "A1\n" << A1 << endl;

        Array B1(5);
        cout << "Enter values for B1[5]\n";
        cin >> B1;

        cout << "B1\n" << B1 << endl;

        A1[0] = B1[0];
        cout << "A1\n" << A1 << endl;

        B1 = A1;
        cout << "B1\n" << B1 << endl;

        int x = A1[1];
        cout << "A1\n" << A1 << endl;
        cout << "x= " << x << endl;

        
        
        return 0;
}

