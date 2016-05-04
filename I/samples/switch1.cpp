#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	for (int year = 2012; year <= 2032; ++year) {
		cout << year << ": ";

		if (year % 4 == 0) {
			cout << "presidential";
		} else if (year % 4 == 2) {
			cout << "congressional";
		} else {
			cout << "local";
		}

		cout << " election year\n";
	}

	return EXIT_SUCCESS;
}
