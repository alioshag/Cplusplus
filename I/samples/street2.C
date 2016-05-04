#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
int main()
{
	const string avenue[] = {
		"Fifth Avenue",
		"Park Avenue (or Fourth Avenue)",
		"Third Avenue",
		"Second Avenue",
		"First Avenue",
		"York Avenue (or Avenue A)",
		"Avenue B"
	};
	const size_t n = sizeof avenue / sizeof avenue[0];

	int street = 42;	//assume East side
	int number = 100;

	if (number < 1 || number > (n - 1) * 100) {
		cerr << "street # " << number << " must be in range 1 to "
			<< (n - 1) * 100 << " inclusive.\n";
		return EXIT_FAILURE;
	}

	const size_t a = (number - 1) / 100;
	cout << "between " << avenue[a] << " and " << avenue[a + 1] << "\n";

	return EXIT_SUCCESS;
}
