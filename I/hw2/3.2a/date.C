#include <iostream>
#include <cstdlib>
#include <ctime>
#include "date.h"
using namespace std;

const int date::length[] = {
	0,                      //dummy element to give january subscript 1
	31,   //january
	28,   //february
	31,   //march
	30,   //april
	31,   //may
	30,   //june
	31,   //july
	31,   //august
	30,   //september
	31,   //october
	30,   //november
	31    //december
};

const int date::pre[] = {
	0,                      //dummy element to give january subscript 1
	0,                      //january
	pre[ 1] + length[ 1],   //february
	pre[ 2] + length[ 2],   //march
	pre[ 3] + length[ 3],   //april
	pre[ 4] + length[ 4],   //may
	pre[ 5] + length[ 5],   //june
	pre[ 6] + length[ 6],   //july
	pre[ 7] + length[ 7],   //august
	pre[ 8] + length[ 8],   //september
	pre[ 9] + length[ 9],   //october
	pre[10] + length[10],   //november
	pre[11] + length[11]    //december
};

date::date()     //Initialize to the current date.
{
	const time_t t = time(0);
	if (t == static_cast<time_t>(-1)) {
		cerr << "time failed\n";
		exit(EXIT_FAILURE);
	}
	const tm *const p = localtime(&t);
	install(p->tm_mon + 1, p->tm_mday, p->tm_year + 1900);
}

bool date::install(int month, int d, int year)
{
	if (month < january || month > december) {
		cerr << "bad month "
			<< month << "/" << d << "/" << year << "\n";
		return false;
	}

	if (d < 1 || d > length[month]) {
		cerr << "bad day "
			<< month << "/" << d << "/" << year << "\n";
		return false;
	}

	day = 365 * year + pre[month] + d - 1;
	return true;
}

int date::julian() const
{
	int j = day % 365;

	if (j < 0) {
		j += 365;
	}

	return j + 1;
}

void date::print() const
{
	div_t divide = div(day, 365);
	if (divide.rem < 0) {
		divide.rem += 365;
		--divide.quot;
	}

	int d = divide.rem + 1;     //Julian date (1 to 365)
	int month;                  //uninitialized variable

	for (month = january; d > length[month]; ++month) {
		d -= length[month];
	}

	cout << month << "/" << d << "/" << divide.quot;
}

ostream& operator<<(ostream& ost, const date& d)
{
	div_t divide = div(d.day, 365);
	if (divide.rem < 0) {
		divide.rem += 365;
		--divide.quot;
	}

	int day = divide.rem + 1;   //Julian date (1 to 365)
	int month;                  //uninitialized variable

	for (month = date::january; day > date::length[month]; ++month) {
		day -= date::length[month];
	}

	return ost << month << "/" << day << "/" << divide.quot;
}

istream& operator>>(istream& ist, date& d)
{
	int month;
	if (!(ist >> month)) {	//if (ist.operator>>(month).operator!()) {
		return ist;
	}

	char c;
	if (!(ist >> c)) {
		return ist;
	}
	if (c != '/') {
		ist.setstate(ios_base::failbit);
		return ist;
	}

	int day;
	if (!(ist >> day)) {
		return ist;
	}

	if (!(ist >> c)) {
		return ist;
	}
	if (c != '/') {
		ist.setstate(ios_base::failbit);
		return ist;
	}

	int year;
	if (!(ist >> year)) {
		return ist;
	}

	if (!d.install(month, day, year)) {
		ist.setstate(ios_base::failbit);
	}

	return ist;
}
