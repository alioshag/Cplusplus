//version1.C p.106
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

void date_next(int *pyear, int *pmonth, int *pday, int count);
void date_next(int *pyear, int *pmonth, int *pday);
void date_print(const int *pyear, const int *pmonth, const int *pday);

int main()
{
        int year = 2012;
        int month = 10;
        int day = 23;

        cout << "How many days forward from ";
        date_print(&year, &month, &day);
        cout << " would you want to go? ";
        
        int count;      //uninitialized variable
        cin >> count; 

        date_next(&year, &month, &day, count);
        
        cout << "The due day will be in => ";
        date_print(&year, &month, &day);
        cout << "\n";
        

        return EXIT_SUCCESS;

}

void date_print(const int *pyear, const int *pmonth, const int *pday)
{
        cout << *pmonth << "/" << *pday << "/" << *pyear;
}


void date_next(int *pyear, int *pmonth, int *pday, int count) //call through function
{
        while (--count >= 0) {
                date_next(pyear, pmonth, pday);
        }
}
void date_next(int *pyear, int *pmonth, int *pday)
{
        if (++*pday > date_length[*pmonth]) {
                *pday = 1;
                if (++*pmonth > 12) {
                        *pmonth = 1;
                        ++*pyear;
                }
        }
}






