/**********************************************************************
filename: date.cpp  Midterm#2
author: Aliohsa Gonzalez
description: This is the implementation of the class Date.
            The interface of the class Date is on the file "date.h"
****************************************************************************/
#include "date.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//CC check for valid input and calculates day_of_year
int Date::date_length[] = {
        0,   //dummy element
       31,   //Janueary
       28,   //February
       31,   //March 
       30,   //April
       31,   //May
       30,   //June
       31,   //July
       31,   //August
       30,   //September
       31,   //October
       30,   //November
       31    //December
};
Date::Date(int initial_month, int initial_day, int initial_year) 
{
        cout << "three argument CC for Date\n ";
        year = initial_year;
        if (LeapYear()){                     //Corrects the table of days for the leap years
                date_length[2] = 29;
        }else {
                date_length[2] = 28;
        }
        if (initial_month < 1 || initial_month > 12) {
                cerr << "bad month " << initial_month << "/" << initial_day
                        << "/" << initial_year << "\n";
                exit(EXIT_FAILURE);
        }
        if (initial_day < 1 || initial_day > date_length[initial_month]) {   //checks for valid day
                cerr << "bad day " << initial_month << "/" << initial_day
                        << "/" << initial_year << "\n";
                exit(EXIT_FAILURE);
        }
        month = initial_month;
        day = initial_day;
}
int Date::DobDays() const      //returns a date as an integer
{
        int count = 0;
        for (int i=1; i < month; ++i){        //finds the day_of_year
            count += date_length[i];    
        }
        return (year * 365) + count + day;
}
void Date::setdate()
{
        cout << "Enter new year: ";
        cin >> year;
        if (LeapYear()){
                date_length[2] = 29;
        }else {
                date_length[2] = 28;
        }
        
        cout << "Enter new month: ";
        cin >> month;
        if (month<1 || month>12)
        {
                cerr << "bad month ";
                exit(1);
        }
        
        cout << "Enter new day: ";
        cin >> day;
        if (day < 1 || day > date_length[month])
        {
                cerr << "bad day";
                exit(1);
        }
}
const int Date::operator+(const Date& rhs) const
{
       return this->DobDays() + rhs.DobDays();
}
const int Date::operator-(const Date& rhs) const
{
        return this->DobDays() - rhs.DobDays();
}
Date& Date::operator=(const Date& rhs)
{
        if (this == &rhs)  //test if rhs is the same as calling obj
        {
                return *this;
        }
        month = rhs.getMonth();
        day = rhs.getDay();
        year = rhs.getYear();
}
ostream& operator<<(ostream& out, const Date &d)
{
        cout << d.getMonth() << "/" << d.getDay() << "/" << d.getYear();
        
        return out;
}

