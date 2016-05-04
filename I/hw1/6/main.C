#include <iostream>
#include <cstdlib>
#include "date.h"
using namespace std;

int main()
{
        date d1(12, 31, 2012);   //parentheses for more than one argument
        d1.print();
        cout << "\n";

        date d2;
        d2.print();
        cout << "\n";

        date().print();
        cout << "\n";

        cout << int() << "\n";
        
        
        return EXIT_SUCCESS;
}
