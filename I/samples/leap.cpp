#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	cout << "Please type a year: ";
	int year;	//uninitialized variable
	cin >> year;
	if (!cin) {
		cerr << "Sorry, that wasn't a number.\n";
		return EXIT_FAILURE;
	}

	if (year % 400 == 0) {
		cout << year << " is a leap year.\n";
	} else if (year % 100 == 0) {
		cout << year << " is not a leap year.\n";
	} else if (year % 4 == 0) {
		cout << year << " is a leap year.\n";
	} else {
		cout << year << " is not a leap year.\n";
	}

	/*
	Could also say
	if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0) {
	*/

	return EXIT_SUCCESS;
}
