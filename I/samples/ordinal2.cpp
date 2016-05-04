#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	cout << "Please type a positive number: ";
	int n;	//uninitialized variable
	cin >> n;
	if (!cin) {
		cerr << "Sorry, that wasn't a number.\n";
		return EXIT_FAILURE;
	}

	cout << "The ordinal form of " << n << " is " << n;
	const int lastDigit = n % 10;
	const int last2digits = n % 100;

	/*
	Handle 11th, 12th, 13th;
	111th, 112th, 113th;
	211th, 212th, 213th; etc.
	*/

	if (11 <= last2digits && last2digits <= 13) {
		cout << "th";
	} else if (lastDigit == 1) {
		cout << "st";
	} else if (lastDigit == 2) {
		cout << "nd";
	} else if (lastDigit == 3) {
		cout << "rd";
	} else {
		cout << "th";
	}

	cout << ".\n";
	return EXIT_SUCCESS;
}
