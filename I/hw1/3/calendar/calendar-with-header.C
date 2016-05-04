//Homework INFO1-CE9264
//date: 10/08/12
//name: Aliosha Gonzalez
//user: ag1917
//filename: calendar-with-header.C
//description: finds the date after user inputs a distance in days
#include <iostream>
#include <cstdlib>
#include <ctime>   //for time_t, time, tm, localtime
#include <climits> //for INT_MAX
#include "calendar.h"
using namespace std;

int main()
{
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
        
        
        
        int distance_yrs = fdistance_yrs(distance);     //Convert distance to years and days
        int distance_days = fdistance_days(distance);

        if (distance_days < 0) {               //Negative distance
                distance_days += 365;
                year -= 1;
        }

       
       
       cout << "Distance_years = " << distance_yrs << "\n"
                << "Distance_days = " << distance_days << "\n";



        
	/*
	Walk distance days into the future.
	"continue" means to abandon this iteration of the loop,
	and go straight back up to the ++i and i < distance
	to begin the next iteration of the loop.
	*/
	
        
        
        for (int i = 0; i < distance_days; ++i) {
		if (day < length[month]) {
			++day;
			continue;
		}

		day = 1;
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

	if (year + distance_yrs < INT_MAX) {
                year += distance_yrs;
        } else {
                cerr << "Can't go beyong year " << INT_MAX << "\n";
                return EXIT_FAILURE;
        }
        
        cout << "The new date is "
		<< month << "/" << day << "/" << year << ".\n";

	return EXIT_SUCCESS;
}
