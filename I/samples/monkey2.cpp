#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	cout << "What year were you born? ";
	size_t year;	//uninitialized variable
	cin >> year;
	if (!cin) {
                cerr << "Sorry, that wasn't a number.\n";
                return EXIT_FAILURE;
        }

	cout << year << " was the year of the ";
	year %= 12;     //means year = year % 12

	if (year == 0) {
		cout << "monkey";
	} else if (year == 1) {
		cout << "rooster";
	} else if (year == 2) {
		cout << "dog";
	} else if (year == 3) {
		cout << "pig";
	} else if (year == 4) {
		cout << "rat";
	} else if (year == 5) {
		cout << "ox";
	} else if (year == 6) {
		cout << "tiger";
	} else if (year == 7) {
		cout << "hare";
	} else if (year == 8) {
		cout << "dragon";
	} else if (year == 9) {
		cout << "snake";
	} else if (year == 10) {
		cout << "horse";
	} else if (year == 11) {
		cout << "sheep";
	}

	cout << ".\n";
	return EXIT_SUCCESS;
}
