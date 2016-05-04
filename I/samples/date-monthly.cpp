//date-yrs_dates.cpp
//Divide the distance between years and days
#include <iostream>
#include <cstdlib>
#include <ctime>   //for time_t, time, tm, localtime
#include <climits> //for INT_MAX
using namespace std;

int main()
{
	const int length[] = {
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
		31,   //October
		30,   //November
		31    //December
	};
	const size_t n = sizeof length / sizeof length[0] - 1;

	const time_t t = time(0);	//Get the current date.
	if (t == -1) {
		cerr << "time failed\n";
		return EXIT_FAILURE;
	}
	const tm *const p = localtime(&t);

	int year = p->tm_year + 1900;
	int month = p->tm_mon + 1;
	int day = p->tm_mday;

	cout << "How many days forward do you want to go from "
		<< month << "/" << day << "/" << year << "? ";
	int distance;	//uninitialized variable
	cin >> distance;

	if (!cin) {
		cerr << "Input failed.\n";
		return EXIT_FAILURE;
	}
        
        
        
        int distance_yrs = distance / 365;     //Convert distance to years and days
        int distance_days = distance % 365;

        if (distance_days < 0) {               //Negative distance
                distance_days += 365;          //converts the negative distance into a positive distance adding 365
                year -= 1;                     //and substracting 1 year
        }

       
       
       cout << "Distance_years = " << distance_yrs << "\n"
                << "Distance_days = " << distance_days << "\n";


       int off_day = length[month] - day;     //month offset of current day
       if (distance_days > off_day) {
               distance -= off_day;
               if (month < n) {
                       ++month;
               } else {
                       month = 1;
               }
               day = 0;
               for (; distance > length[month]; distance -= length[month]) {
                       if (month < n) {
                               ++month;
                               continue;
                       }
                       month = 1;
                       if (year < INT_MAX) {
                               ++year;
                               continue;
                       }
	               cerr << "Can't go beyond year " << INT_MAX << "\n";
	               return EXIT_FAILURE;
               }
       }
               
       --month;
       day += distance; 
       
       
       cout << "The new date is "
		<< month << "/" << day << "/" << year << ".\n";

	return EXIT_SUCCESS;
}
