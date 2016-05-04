/*******************************************
file : employee.h
synopsis: this is the interface for the class Employee intended to 
          be used as a base class to derive classes for different
          kinds of employees.
 ********************************************/
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using std::string;

class Employee
{
        public:
                Employee();
                Employee(const string& theName, const string& theSsn);
                string getName() const;
                string getSsn() const;
                double getNetPay() const;
                void setName(const string& newName);
                void setSsn(const string& newSsn);
                void setNetPay(double newNetPay);
                void printCheck();
        private:
                string name;
                string ssn;
                double netPay;     
};

#endif  //EMPLOYEE_H
