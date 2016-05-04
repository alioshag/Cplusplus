#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	for (int year = 2012; year <= 2032; ++year) {
		cout << year << ": ";

		switch (year % 4) {
		case 0:
			cout << "presidential ";
		case 2:
			cout << "congressional ";
		default:
			cout << "local\n";
		}
	}

	return EXIT_SUCCESS;
}
