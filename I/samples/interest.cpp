#include <iostream>
#include <iomanip>	//for setprecision
#include <cstdlib>
#include <cmath>	//for log (natural logarithm)
using namespace std;

int main()
{
	//How many years does it take for the principal to double?

	const double rate = .06; //6 percent
	const double factor = 1 + rate;
	const double principal = 100;
	double amount = principal;
	int year = 0;

	cout << fixed << setprecision(2);  //because a dollar has 100 cents

	do {
		amount *= factor;	//means amount = amount * factor;
		++year;                 //means year = year + 1;
		cout << year << "\t" << amount << "\n";		//tab character
	} while (amount < 2 * principal);

	cout << resetiosflags(ios_base::floatfield)	//Turn off the "fixed".
		<< setprecision(6)			//original precision
		<< "\n"
		<< log(2.0) / log(factor) << "\n";

	return EXIT_SUCCESS;
}
