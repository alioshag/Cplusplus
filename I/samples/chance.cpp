#include <iostream>	//for cin, cout, clear, ignore, <<, >>
#include <cstdlib>
#include <climits>	//for INT_MAX
using namespace std;

int main()
{
	cout << "Please type an integer in the range 1 to 10 inclusive\n"
		<< "and press RETURN.\n";
	int i;	//uninitialized variable: born with an unpredictable value.

	for (;;) {
		cin >> i;

		if (!cin) {
			cerr << "Sorry, that wasn't a number.  Try again.\n";

			/*
			The following statements are needed
			if you want to make another attempt at input
			after a previous attempt failed.
			*/
			cin.clear();               //restore cin to health
			cin.ignore(INT_MAX, '\n'); //discard bad chars up to '\n'
		}

		else if (i < 1 || i > 10) {
			cerr << "Sorry, the integer must be in the range\n"
				"1 to 10 inclusive.  Try again.\n";
		}

		else {
			break;
		}
	}

	cout << "The number was " << i << ".\n";
	return EXIT_SUCCESS;
}
