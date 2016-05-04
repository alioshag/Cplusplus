#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	for (int year = 2012; year <= 2032; ++year) {
		cout << year << ": ";

		switch (year % 4) {
		case 0:
			cout << "presidential";
			break;
		case 2:
			cout << "congressional";
			break;
		default:
			cout << "local";
			break;
		}

		cout << " election year\n";
	}

	return EXIT_SUCCESS;
}
