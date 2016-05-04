/*******************************
file: test-class=employee.cpp
 *
 * ******************************/

#include <iostream>
#include <cstdlib>
#include "employee.h"
//#include "employee.cpp"
using std::cout;
using std::string;
using std::endl;

int main()
{
        cout<< "Creating Employee E1";
        Employee E1;

        cout << "the name of E1 is "<< E1.getName() << endl;
        cout << "the ssn of E1 is "<< E1.getSsn() << endl;
        cout << "the netPay of E1 is "<< E1.getNetPay() << endl;
        

        
        return (0);
}
