//filename: tstamp.h
//header file of class tstamp


#ifndef TSTAMPH
#define TSTAMPH
#include <iostream>
using namespace std;

class tstamp {
        char key;
        int year;
        int month;
        int day;
public:
        tstamp(int initial_month, int initial_day, int initial_year, char c);
        void print() const;
        //void julian();
};
#endif
