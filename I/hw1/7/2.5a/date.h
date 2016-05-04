//INFO1-CE9264
//Filename: date.h H2.5a p142
//File modified for H2.5a p142, default constructor declaration added
//Declaration of the class on a header file
//Filename: date.h H2.5a p142
//name: Aliosha Gonzalez
//user: ag1917
//File modified for H2.5a p142, default constructor declaration added
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
        date();   //default constructor
        void print() const {cout << month << "/" << day << "/" << year;}
        void next(int count = 1);    //count=1 is a default value
        int julian() const;
};
#endif
