//version3.C p.115
//Call member functions of an object
#include <iostream>
#include <cstdlib>
#include "date.h"
using namespace std;

int main()
{       
        //Construct d by passing three arguments to the constructor for d
        date d(1, 1, 2012);

        cout << "How many days forward from ";
        d.print();
        cout << " would you want to go? ";
        
        int count;      //uninitialized variable
        cin >> count; 

        d.next(count);
        
        cout << "The due day will be in => ";
        d.print();
        cout << "\n";
        

        return EXIT_SUCCESS;

}
