#include <iostream>
#include <cstdlib>
#include "date.h"
using namespace std;

int main()
{
        date d1(12, 31, 2012);   //parentheses for more than one argument
        d1.print();
        cout << "\n";

        date d2;                //no pareantheses for no arguments
        d2.print();
        cout << "\n";

        date().print();         //construct an anonymous date; call its print function
        cout << "\n";

        cout << int() << "\n";  //construct an anonymous int with the value 0
        return EXIT_SUCCESS;
}
