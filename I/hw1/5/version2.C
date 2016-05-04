//version2.C p.108
//Variables in a struct. Pass structure to a function.
#include <iostream>
#include <cstdlib>
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

struct date {
        int year;
        int month;
        int day;
};

void date_next(date *pdate, int count);             //struct date
void date_next(date *pdate);
void date_print(const date *pdate);

int main()
{
        date d = {2012, 1, 1};

        cout << "How many days forward from ";
        date_print(&d);
        cout << " would you want to go? ";
        
        int count;      //uninitialized variable
        cin >> count; 

        date_next(&d, count);
        
        cout << "The due day will be in => ";
        date_print(&d);
        cout << "\n";
        

        return EXIT_SUCCESS;

}

void date_print(const date *pdate)
{
        cout << pdate->month << "/" << pdate->day << "/" << pdate->year;
}


void date_next(date *pdate, int count) //call through function
{
        while (--count >= 0) {
                date_next(pdate);
        }
}
void date_next(date *pdate)   //date is a struct
{
        if (++pdate->day > date_length[pdate->month]) {
                pdate->day = 1;
                if (++pdate->month > 12) {
                        pdate->month = 1;
                        ++pdate->year;
                }
        }
}






