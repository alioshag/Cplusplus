//Filename: date.C H2.4b p129
//Definitions of var and functions (no declarations) on header file.
#include <iostream>
#include <cstdlib>
#include "date.h"
using namespace std;


const int date_length[] = {
        0,   //dummy element so that January will have subscript 1
        31,   //January
        28,   //February
        31,   //March
        30,   //April
        31,   //May
        30,   //June
        31,   //July
        31,   //August
        30,   //September
        31,  //October
        30,  //November
        31   //December            
};

date::date(int initial_month, int initial_day, int initial_year) //converts day/month/year date to one integer date
{
        if (initial_month < 1 || initial_month > 12) {
                cerr << "bad month " << initial_month << "/" << initial_day 
                        << "/" << initial_year << "\n";
                exit(EXIT_FAILURE);
        }
        if (initial_day < 1 || initial_day > date_length[initial_month]) {
                cerr << "bad date " << initial_month << "/" << initial_day
                        << "/" << initial_year << "\n";
                exit(EXIT_FAILURE);
        }
        //one number date is the sum of days added by the representation of 
        //month,day and year from a month/date/year date.
        //
        day = initial_day + (initial_year * 365) - 1;  //adds days accounted from initial_day + initial_year  
                                                       //-1 to follow rule January 1st year 0, should be day = 0. 
        
        for (int m=initial_month; --m > 0; day += date_length[m]) {   //adds days accounted from the initial_month
        }
}
int date::julian() const   //converts date to julian date
{
        int djulian = day % 365;

        if (djulian < 0) {
                djulian += 365;
        }
        
        return (djulian + 1);   //+1 to follow rule January 1st, julian = 1. 
}
void date::print() const   //finds month/day/year to print the date from one integer date (day) format
{
        const div_t d = div(day, 365);

        int year = d.quot;        //year
        int t_day = d.rem;        //

        if (t_day < 0) {          //adjust for negative date
                t_day += 365;
                --year;
        }
        
        ++t_day;                  //adjust for the January 1st, day = 0 rule
        
        int month = 1;            //month
        for (; t_day > date_length[month]; t_day -= date_length[month++]) {
        }
                
        cout << month << "/" << t_day << "/" << year;
    
        
}
