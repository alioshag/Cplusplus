#include <iostream>
#include <cstdlib>
#include <limits>   //for numeric_limits
using namespace std;

int main()
{
	cout << "How many miles did you drive? ";
	double miles;	//uninitialized variable
	cin >> miles;

	if (!cin) {
		cerr << "Sorry, that wasn't a number.\n";
		return EXIT_FAILURE;
	}

	cout << "How many gallons did you use? ";
	double gallons;	//uninitialized variable
	cin >> gallons;

	if (!cin) {
		cerr << "Sorry, that wasn't a number.\n";
		return EXIT_FAILURE;
	}

	double mpg;	//uninitialized variable

	if (gallons == 0) {
		mpg = numeric_limits<double>::infinity();
	} else {
		mpg = miles / gallons;
	}

	cout << "Then you got " << mpg << " miles per gallon.\n";
	return EXIT_SUCCESS;
}
