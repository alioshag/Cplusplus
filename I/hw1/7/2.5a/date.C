//File modified for H2.5a p142, default constructor defined
//Definitions of var and functions (no declarations) on header file.
#include <iostream>
#include <cstdlib>
#include <ctime>
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

date::date(int initial_month, int initial_day, int initial_year)
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
        year = initial_year;
        month = initial_month;
        day = initial_day;
}
date::date()      //default constructor --> no arguments
                  //takes current date and assigns it to the data class members 
{
        const time_t t = time(0);

        if (t == static_cast<time_t>(-1)) {
                cerr << ": time failed\n";
                exit(EXIT_FAILURE);                
        }

        const tm *const p = localtime(&t);

        day = p->tm_mday;
        month = p->tm_mon + 1;
        year = p->tm_year + 1900;
}
void date::next(int count) //call through function
{
        const int quotient = count / 365;
        int remainder = count % 365;
        
        if (remainder < 0) {               //adjust for negative dates
                remainder += 365;
                --year;
        }
        year += quotient; 
        count = remainder + day;
        
        while (count > date_length[month]) {
                count -= date_length[month];
                if (++month > 12) {
                        month = 1;
                        ++year;
                }
       }
       day = count;         
}
int date::julian() const   //converts date to julian date
{
        int djulian = day;
        
        for (int m = month; --m > 0; djulian += date_length[m]) {   //calculates de julian day                
        }
        return djulian;

}
