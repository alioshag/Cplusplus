#include <iostream>
#include <cstdlib>
#include <string>	//for string
using namespace std;

int main()
{
	string animal[] = {
		"monkey",    // 0
		"rooster",   // 1
		"dog",       // 2
		"pig",       // 3
		"rat",       // 4
		"ox",        // 5
		"tiger",     // 6
		"hare",      // 7
		"dragon",    // 8
		"snake",     // 9
		"horse",     //10
		"sheep"      //11
	};
	const size_t n = sizeof animal / sizeof animal[0];

	cout << "What year were you born? ";
	size_t year; //Uninitialized variable. size_t can hold only non-negative
	cin >> year;

	if (!cin) {
		cerr << "Sorry, that wasn't a number.\n";
		return EXIT_FAILURE;
	}

	cout << year << " was the year of the " << animal[year % n] << ".\n";
	return EXIT_SUCCESS;
}
