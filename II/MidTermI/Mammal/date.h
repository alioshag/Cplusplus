/***********************************************************************
file: date.h (Header file)  Midterm#2
author: Aliosha Gonzalez
description: Interface for the class Date. This version is not using Day_of_year.
*************************************************************************/
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <cstdlib>
using namespace std;

class Date
{
        public:
                Date(): month(1), day(1), year(0){cout << "Default CC Date\n";} //default const to 1/1/1
                Date(int initial_month, int initial_day, int initial_year);//CC checks for valid input
                Date(const Date& d)
                        :month(d.month), day(d.day), year(d.year){cout << "Copy CC Date\n";}
                ~Date(){cout << "Destructor Date\n";}
                
                //accessors
                int getMonth() const {return month;}
                int getDay() const {return day;}
                int getYear() const {return year;}
                int DobDays() const;    //returns birthday as an integer of days
                bool LeapYear() {return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));}    //returns true if leap year is found
                
                //mutators
                void setdate();
                
                //operators
                const int operator+(const Date& rhs) const;
                const int operator-(const Date& rhs) const;
                Date& operator=(const Date& rhs);
                
                //friend functions
                friend ostream& operator<<(ostream& out, const Date &d);
        private:
                int month;
                int day;
                int year;
                static int date_length[];
};
#endif
