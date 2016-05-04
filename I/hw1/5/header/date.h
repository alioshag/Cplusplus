//date.h p.120
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
        void print() const {cout << month << "/" << day << "/" << year;}
        void next(int count);
        void next();
};
#endif
