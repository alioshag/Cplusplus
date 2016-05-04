/******************************************************************
 * filename: "ArrayTemplateTest.cpp"
 * author: Aliosha Gonzalez
 * synopsis: This is a test file for "ArrayTemplate.h"
 * *****************************************************************/
#include "ArrayTemplate.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
        Array<float> a(10);
        for (int i = 0; i < 10; i++)
                a[i] = static_cast<float>(i);
        cout << "array a\n" << a << endl;

        Array<float> b(5);
        cout << "fill array b(5)\n";
        cin >> b;
        cout << "print array b\n" << b;

        a[0] = b[0];
        cout << "a[0] = b[0]\n" << "print array a\n" << a << endl;

        a = b;
        cout << "a = b\n" << "print array a\n" << a << endl;

        return 0;
}
