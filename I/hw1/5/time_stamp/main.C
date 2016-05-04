//Homework INFO1-CE9264
//date:10/15/12
//name: Aliosha Gonzalez
//record the time stamp of an entered key
//Filename: main.C
//Definitions at tstamp.C
//Declarations at tstamp.h

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tstamp.h"
using namespace std;

int main() 
{
        cout << "Please enter a key to record the time stamp => ";
        char c;
        cin >> c;
        if (!cin) {
                cout << "this key is not valid";
                return EXIT_FAILURE;
        }
             
        time_t t = time(0);
        if (t == -1) {
                cerr << "Time failed\n";
                return EXIT_FAILURE;
        }
        const tm *const p = localtime(&t);
        
        int initial_year  = p->tm_year + 1900;
        int initial_month = p->tm_mon + 1;
        int initial_day   = p->tm_mday;
        
        cout << "==> " << initial_month << "/" << initial_day 
                << "/" << initial_year << "\n";

        tstamp ts(initial_month, initial_day, initial_year,c);

        cout << " The key and time stamp captured was => ";
        ts.print();
        cout << "\n";
        return EXIT_SUCCESS;
}
