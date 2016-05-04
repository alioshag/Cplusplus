/***************************************************
 * filename: "fibonacci.h"
 * author: Aliosha Gonzalez
 * synopsis: This is an interface and implementation of the fibonacci function. 
 * ***************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

int fibonacci(int N);

int fibonacci(int N)
{
        if (N == 0) return 0;
        if (N == 1) return 1;
        
        return fibonacci(N-1) + fibonacci(N-2);
}

int main()
{
        cout << fibonacci(5) << endl;
        
        return 0;
}
