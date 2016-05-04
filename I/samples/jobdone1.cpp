#include <iostream>
#include <cstdlib>
#include <iomanip>  //for setfill and setw
using namespace std;

int main()
{
	//Current time (e.g., 6:45).
	int hour = 6;
	int minute = 45;

	//How long will the job take (e.g., 2 hours and 20 minutes)
	int jhour = 2;
	int jminute = 20;

	//Total number of minutes from 12:00 to end of job.
	int total = 60 * (hour + jhour) + minute + jminute;

	//Break the total back down into hours and minutes.
	hour   = total / 60;	//quotient
	minute = total % 60;	//remainder

	cout << "The job will be finished at " << hour << ":";

	//Print the minute as a two-digit number.
	//Single, not double, quotes around the zero.
	cout << setfill('0') << setw(2) << minute << ".\n";

	cout << left << setfill('*') << setw(30) << "John Doe" << "\n";

	return EXIT_SUCCESS;
}
