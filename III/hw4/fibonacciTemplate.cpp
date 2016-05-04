/*******************************************************************
 * filename: "fibonacciTemplate.cpp"
 * author: Aliosha Gonzalez
 * synopsis: This is a template of the fibonacci function. 
 * *****************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

template<class T>
T fibonacci(T N)
{
        if (N == 0) return 0;
        if (N == 1) return 1;

        return fibonacci(N-1) + fibonacci(N-2);        
}

int main ()
{
        cout << "int   : " << fibonacci(int(6)) << endl;
        cout << "float : " << fibonacci(float(7)) << endl;
        cout << "double: " << fibonacci(double(8)) << endl << endl;

        return 0;
}

