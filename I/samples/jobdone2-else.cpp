#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
	//Current time, e.g. 11:45 a.m.
	int hour = 11;
	int minute = 45;
	int m = 1;	//1 means a.m.; -1 means p.m.

	//How long will the job take (e.g., 2 hours and 20 minutes)
	int jhour = 2;
        int jminute = 20;

	int total = 60 * (hour + jhour) + minute + jminute;

	//Break the total back down into hours and minutes.
        hour   = total / 60;	//quotient
	minute = total % 60;	//remainder

        while (hour > 12) {          //should be while (hour > 12) {
		hour = hour - 12; //can be abbreviated to hour -= 12;
		m = -m;           //toggle the a.m./p.m.
	}

	cout << "The job will be finished at " << hour << ":"
		//Print the minute as a two-digit number.
		<< setfill('0') << setw(2) << minute << " ";

	if (m == 1) {
		cout << "a.m.\n";
	}else {
		cout << "p.m.\n";
	}

	return EXIT_SUCCESS;
}
