/******************************************************
file: employee.cpp
synopsis: this is the implementation of the class Employee.
          The interface for the class Employee is in the header file employee.h
 * *******************************************************/
#include <string>
#include <cstdlib>
#include <iostream>
#include "employee.h"
using std::string;
using std::cout;


Employee::Employee() : name("no name yet"), ssn("no number yet"), netPay(0){}
Employee::Employee(const string& theName, const string& theSsn)
         : name(theName), ssn(theSsn), netPay(0){}
string Employee::getName() const {return name;}
string Employee::getSsn() const {return ssn;}
double Employee::getNetPay() const {return netPay;}
void Employee::setName(const string& newName)
{
        name = newName;
}
void Employee::setSsn(const string& newSsn)
{
        ssn = newSsn;
}
void Employee::setNetPay(double newNetPay)
{
        netPay = newNetPay;
}
void printcheck()
{
        cout << "\nERROR: printCheck FUNCTION CALLED FOR AN \n"
                << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
                << "Check with the author of the program about this bug.\n";
        exit(1);
}
