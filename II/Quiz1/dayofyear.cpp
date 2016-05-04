/***********************************************************************
file: dayofyear.cpp
author: Aliosha Gonzalez
description: Write a program that creates a class DayOfYear that has the following attributes:
- int day, month, year
- int day_of_year
- construct that accepts date as 3 inputs integers(construct checks for valid input dates
- destructor
- calculates the day_of_year in the constructor
- member function taht returns the day_of_year
- takes into consideration leap years
hint: use lookup table for enumarating #days in each month
Provide source and output demonstrating the program running correctly. 
*************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

class DateOfYear {
public:
        DateOfYear():month(1), year(1900), day(1), day_of_year(1){;} //default const to 1/1/1900 
        DateOfYear(int month, int day, int year); //const check for valid input and calculates day_of_year
        DateOfYear(DateOfYear& d):month(d.month), year(d.year), day(d.day), day_of_year(d.day_of_year) {cout << "Copy constructor\n";}
        ~DateOfYear(){cout << " destructor ";}
        void print() const{cout << month << "/" << day << "/" << year;}
        int getDayofyear()const{return day_of_year;}
        bool LeapYear() {return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));}    //returns true if leap year is found
private:        
        int month;
        int day;
        int year;
        int day_of_year;
        static int date_length[];
};
int DateOfYear::date_length[] = {
        0,    //dummy element
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
        31   //December
};
int main ()
{
        cout << "D5( 1, 1,1900) -->";  
        DateOfYear D5;
        D5.print();
        cout << " day_of_year=" << D5.getDayofyear() << endl;
        
        cout << "D1( 3, 1,2013) -->";  
        DateOfYear D1(3, 1, 2013);
        D1.print();
        cout << " day_of_year=" << D1.getDayofyear() << endl;
        
        cout << "D2( 2,29,2000) -->";  
        DateOfYear D2(2,29,2000);
        D2.print();
        cout << " day_of_year=" << D2.getDayofyear() << endl;
        
        cout << "D4( 7,25,2013) -->";  
        DateOfYear D4(7, 25, 2013);
        D4.print();
        cout << " day_of_year=" << D4.getDayofyear() << endl;
        
        cout << "D3( 2,29,2013) -->";  
        DateOfYear D3(2, 29, 2013);
        D3.print();
        cout << " day_of_year=" << D3.getDayofyear() << endl;
        
        return 0;
}
//const check for valid input and calculates day_of_year
DateOfYear::DateOfYear(int initial_month, int initial_day, int initial_year) 
{
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
        int count = 0;
        for (int i=1; i < initial_month; ++i){        //finds the day_of_year
            count += date_length[i];    
        }
        day_of_year = count + initial_day;
        month = initial_month;
        day = initial_day;
}
