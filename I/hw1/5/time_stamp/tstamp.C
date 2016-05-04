//Filename: tstamp.C
//Definitions of var and functions (no declarations) on header file
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tstamp.h"
using namespace std;

tstamp::tstamp(int initial_month, int initial_day, int initial_year, char c)
{
        month = initial_month;
        day = initial_day;
        year = initial_year;
        key = c;
}
void tstamp::print() const //function definition
{
        cout << key << ": " << month << "/" << day << "/" << year << ".";
}
