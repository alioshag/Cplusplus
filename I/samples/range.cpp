#include <iostream>
#include <cstdlib>
#include <climits>   //for INT_MAX
using namespace std;

int main()
{
	cout << "Please type an even integer in the range 0 to 10 inclusive: ";
	int i;	//uninitialized variable, must be declared outside the loop

	for (;;) {
		cin >> i;

		if (!cin) {
			cerr << "Sorry, you must input a number.\n";
			//Restore cin to health.
			cin.clear();
			//Discard everything up to and including the '\n'.
			cin.ignore(INT_MAX, '\n');
		} else if (i < 0) {
			cerr << "Sorry, it can't be less than zero.\n";
		} else if (i > 10) {
			cerr << "Sorry, it can't be greater than 10.\n";
		} else if (i % 2 != 0) {
			cerr << "Sorry, it must be even.\n";
		} else {
			break;
		}

		cout << "Try again: ";
	}

	cout << "Thank you, the number was " << i << ".\n";
	return EXIT_SUCCESS;
}
