//Homework INFO1-CE9264
//date: 10/01/12
//name: Aliosha Gonzalez
//user: ag1917
//Filename: date-montly1.C
//DEscription: Divide the distance between years and days
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

	cout << "How many days forward or backward do you want to go from "
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
                day += 365;          //converts the negative distance into a positive distance adding 365
                year -= 1;                     //and substracting 1 year
        }

       
       
       cout << "Distance_years = " << distance_yrs << "\n"
                << "Distance_days = " << distance_days << "\n";

       
       int off_day = length[month] - day;
//       int sum_day = off_day + length[month];
       
       cout << "offday " << off_day << " \n";

       
       if (distance_days > off_day) {
               int total_days = 0;      //sum of total of days added by months
               int total_days_before = 0;
               for (; distance_days - off_day > total_days;total_days += length[month]) {
                       if (month < n) {
                               ++month;
                       } else {
                               month = 1;
                               if (year < INT_MAX) {
                                       ++year;
                               }
                       }
                       total_days_before = total_days;
               }
               day = distance_days - off_day - total_days_before;
       } else {
               day += distance_days;
       }
       
       year += distance_yrs; 

       
       cout << "The new date is "
		<< month << "/" << day << "/" << year << ".\n";

	return EXIT_SUCCESS;
}
