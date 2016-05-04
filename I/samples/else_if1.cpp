#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	cout << "What is our profit? ";
	int profit;	//uninitialized variable
	cin >> profit;
	if (!cin) {
		cerr << "Sorry, that wasn't a number.\n";
		return EXIT_FAILURE;
	}

	cout << "What is our loss? ";
	int loss;	//uninitialized variable
	cin >> loss;
	if (!cin) {
		cerr << "Sorry, that wasn't a number.\n";
		return EXIT_FAILURE;
	}

	if (profit > loss) {
		cout << "We're making money.\n";
	} else {
		if (profit < loss) {
			cout << "We're losing money.\n";
		}
	}

	//Remain silent if breaking even.
	return EXIT_SUCCESS;
}
