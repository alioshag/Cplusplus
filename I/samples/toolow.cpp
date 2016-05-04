#include <iostream>	//for cin, cout, clear, ignore, <<, >>
#include <cstdlib>
#include <climits>	//for INT_MAX
using namespace std;

int main()
{
	cout << "I am thinking of a number in the range 1 to 100 inclusive.\n"
		<< "Keep trying until you guess it.\n\n";

	const int n = 56;

	for (;;) {
		cout << "Go ahead: ";
		int i;		//uninitialized variable
		cin >> i;

		if (!cin) {
			cerr << "Input failed.";
			//Restore cin to health.
			cin.clear();
			//Discard everything up to and including the '\n'.
			cin.ignore(INT_MAX, '\n');
		} else if (i < n) {
			cout << "Too low.";
		} else if (i > n) {
			cout << "Too high.";
		} else {
			break;
		}

		cout << "  Try again.\n";
	}

	cout << "That's right, the number was " << n << ".\n";
	return EXIT_SUCCESS;
}
