#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	//Output graph paper.

	cout << "How many rows (e.g., 10)? ";
	int nrows;	//uninitialized variable
	cin >> nrows;

        if (!cin) {
                cerr << "Sorry, that wasn't a number.\n";
                return EXIT_FAILURE;
        }

	cout << "How many columns (e.g., 10)? ";
	int ncols;	//uninitialized variable
	cin >> ncols;

        if (!cin) {
                cerr << "Sorry, that wasn't a number.\n";
                return EXIT_FAILURE;
        }

	for (int r = 0; r < nrows; ++r) {
		for (int c = 0; c < ncols; ++c) {
			cout << "+----";
		}
		cout << "\n";

		for (int c = 0; c < ncols; ++c) {
			cout << "|    ";
		}
		cout << "\n";
	}

	return EXIT_SUCCESS;
}
