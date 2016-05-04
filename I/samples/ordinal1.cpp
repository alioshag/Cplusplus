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

	if (lastDigit == 1) {
		cout << "st";
	} else if (lastDigit == 2) {
		cout << "nd";
	} else if (lastDigit == 3) {
		cout << "rd";
	} else {
		cout << "th";   //all other numbers
	}

	cout << ".\n";
	return EXIT_SUCCESS;
}
