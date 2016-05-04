/***********************************************
file: salariedemployee.h
ynopsis: interface of the class
**********************************************/
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include "employe.h"

using std::string;

class SalariedEmployee : Public Employee
{
        public: 
                SalariedEmployee();
                SalariedEmployee (const string& theName, const string& theSsn,
                                double theWeeklySalary);
                double getSalary() const;
                void setSalary(double newSalary);
                void printCheck( );
        private:
                double salary; //weekly
};

#endif //SALARIEDEMPLOYEE_H
