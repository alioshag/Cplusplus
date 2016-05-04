#include <iostream>
#include <iomanip>  //for fixed, setprecision, setw ("set width")
#include <cstdlib>
#include <cmath>    //for natural log, abs
using namespace std;

/*
Estimate is most accurate near interest rate of 8%.

Thanks to "fixed", setprecision specifies the number of digits to the right of
the decimal point.  Without "fixed", setprecision would specify the number of
significant digits.
*/

int main()
{
	cout << fixed << setprecision(4);

	cout
		<< "interest     years to\n"
		<< "    rate       double    72 / rate        error\n"
		<< "-----------------------------------------------\n";

	for (int rate = 1; rate <= 15; ++rate) {

		const double years = log(2.0) / log(1 + rate / 100.0);
		const double estimate = 72.0 / rate;

		cout << setw(8) << rate
			<< setw(13) << years
			<< setw(13) << estimate
			<< setw(13) << abs(years - estimate) << "\n";
	}

	return EXIT_SUCCESS;
}
