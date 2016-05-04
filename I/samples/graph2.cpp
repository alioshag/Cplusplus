#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	//Output graph paper with 10 columns.

	cout << "How many rows (e.g., 10)? ";
	int nrows;	//uninitialized variable
	cin >> nrows;

	if (!cin) {
		cerr << "Sorry, that wasn't a number.\n";
		return EXIT_FAILURE;
	}

	for (int r = 0; r < nrows; ++r) {
		cout << "+----+----+----+----+----+----+----+----+----+----\n";
		cout << "|    |    |    |    |    |    |    |    |    |    \n";
	}

	return EXIT_SUCCESS;
}
