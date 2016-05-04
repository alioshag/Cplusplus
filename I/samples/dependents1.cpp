#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	cout << "How many dependents do you have? ";
	int dependents;	//uninitialized variable
	cin >> dependents;
	if (!cin) {
		cerr << "Input failed.\n";
		return EXIT_FAILURE;
	}

	if (dependents < 0) {
		cerr << "Must be a non-negative number.\n";
		return EXIT_FAILURE;
	}

	if (dependents == 0) {
		cout << "You can deduct 30 dollars.\n";
	} else if (dependents == 1) {
		cout << "You can deduct 50 dollars.\n";
	} else if (dependents == 2) {
		cout << "You can deduct 65 dollars.\n";
	} else if (dependents == 3) {
		cout << "You can deduct 95 dollars.\n";
	} else if (dependents == 4) {
		cout << "You can deduct 105 dollars.\n";
	} else if (dependents == 5) {
		cout << "You can deduct 120 dollars.\n";
	} else {
		cout << "You can deduct 124 dollars.\n";
	}

	return EXIT_SUCCESS;
}
