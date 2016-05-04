//Filename: date.C p.120
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
void date::next(int count) //call through function
{
        while (--count >= 0) {
                next();
        }
}
void date::next()   //date is a class
{
        if (++day > date_length[month]) {
                day = 1;
                if (++month > 12) {
                        month = 1;
                        ++year;
                }
        }
}
