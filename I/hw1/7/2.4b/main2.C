//Homework INFO-CE9264
//date: 10/22/12
//name: Aliosha Gonzalez
//user: ag1917
//Filename: main.C 
//author: Mark Meretzky
//Description: Original file has been modified. The array at test_julian() function has been modified.
//
//
#include <iostream>
#include <cstdlib>
//#include <ctime>
#include <string>
#include <sstream>

#include "date.h"
using namespace std;

string getprint(const date& d);
string getprint(int month, int day, int year);
string  getname(int month, int day, int year);

bool test_print (const date& d, int month, int day, int year);
bool test_julian(const date& d, int month, int day, int year);
bool test_next  (const date& d, int month, int day, int year);

const struct {
	const char *name;
	int length;
} a[] = {
	{0,            0}, //Dummy element so that January will have subscript 1
	{"January",   31},
	{"February",  28},
	{"March",     31},
	{"April",     30},
	{"May",       31},
	{"June",      30},
	{"July",      31},
	{"August",    31},
	{"September", 30},
	{"October",   31},
	{"November",  30},
	{"December",  31}
};

int main()
{
	cout << "Be patient...\n";

	//const time_t t = time(0);
	//const int year = localtime(&t)->tm_year + 1900;

	for (int year = -1; year <= 1; ++year) {
		for (int month = 1; month <= 12; ++month) {
			for (int day = 1; day <= a[month].length; ++day) {
				const date d(month, day, year);
				if (!test_print(d, month, day, year) ||
					!test_julian(d, month, day, year) ||
					!test_next(d, month, day, year)) {
					return EXIT_FAILURE;
				}
			}
		}
	}

	cout << "date::print, julian, and next passed all tests.\n";
	return EXIT_SUCCESS;
}

bool test_print(const date& d, int month, int day, int year)
{
	const string s = getprint(d);
	const string correct = getprint(month, day, year);

	if (s == correct) {
		return true;
	}

	cout << getname(month, day, year)
		<< " should print as \"" << correct << "\", not as \"" << s
		<< "\".\n";
	return false;
}

bool test_julian(const date& d, int month, int day, int year)
{
/*	static const int a[] = {
		0,   //dummy element
		0,
		a[ 1] + 31,
		a[ 2] + 28,
		a[ 3] + 31,
		a[ 4] + 30,
		a[ 5] + 31,
		a[ 6] + 30,
		a[ 7] + 31,
		a[ 8] + 31,
		a[ 9] + 30,
		a[10] + 31,
		a[11] + 30
	};
*/
	static const int a[] = {
		0,   //dummy element
		0,
		31,
		59,
		90,
		120,
		151,
		181,
		212,
		243,
		273,
		304,
		334
	};

        
	const int j = d.julian();
	const int julian = a[month] + day;
        //cerr << "Mark's julian " << julian << " " << "a[month] = " << a[month] << " "; 

	if (j == julian) {
		return true;
	}

	cout << "Julian date of " << getname(month, day, year)
		<< " should be " << julian << ", not " << j << ".\n";
	return false;
}

bool test_next(const date& d1, int month, int day, int year)
{
	for (int i = -2 * 365; i < 2 * 265; ++i) {
		div_t divide = div(i, 365);
		if (divide.rem < 0) {
			divide.rem += 365;
			--divide.quot;
		}

		int y = year + divide.quot;
		int m = month;
		int d = day + divide.rem;

		while (d > a[m].length) {
			d -= a[m].length;
			if (++m > 12) {
				m = 1;
				++y;
			}
		}

		date d2 = d1;
		if (i == 1) {
			//make sure argument has default value of 1
			d2.next();
		} else {
			d2.next(i);
		}

		const string s = getprint(d2);
		const string correct = getprint(m, d, y);

		if (s != correct) {
			cout << abs(i) << " day" << (i == 1 ? "" : "s") << " "
				<< (i < 0 ? "before " : "after ")
				<< getname(month, day, year)
				<< " should be \"" << correct
				<< "\", not \"" << s << "\".\n";
			return false;
		}
	}

	return true;
}

//Return a string containing the standard output of d.print

string getprint(const date& d)
{
	streambuf *const p = cout.rdbuf();        //Save the standard output.
	ostringstream ostr;
	cout.rdbuf(ostr.rdbuf());    //Redirect standard output, like C freopen.
	d.print();           //The standard output of this print goes into ostr.
	cout.rdbuf(p);                            //Restore the standard output.
	return ostr.str();
}

//Return the string representing this date.

string getprint(int month, int day, int year)
{
	ostringstream ostr;
	ostr << month << "/" << day << "/" << year;
	return ostr.str();
}

string getname(int month, int day, int year)
{
	ostringstream ostr;
	ostr << a[month].name << " " << day << ", " << year;
	return ostr.str();
}
