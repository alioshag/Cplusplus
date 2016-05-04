//Filename: date.h H2.4a p126
//Declaration of the class on a header file


#ifndef DATEH
#define DATEH
#include <iostream>
using namespace std;

class date {
        int year;
        int month;
        int day;
public:
        date(int initial_month, int initial_day, int initial_year);
        void print() const {cout << month << "/" << day << "/" << year;} //inline member function
        void next(int count = 1);    //non-inline member funct. (count=1 is a default value)
        int julian() const;
};
#endif
