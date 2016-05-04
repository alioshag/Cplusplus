#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int street = 42;	//assume East side
	int number = 100;

	if (number < 1) {
		cerr << "street # " << number << " must be positive.\n";
		return EXIT_FAILURE;
	}

	if (number <= 100) {
		cout << "between Fifth and Park (or Fourth)\n";
	} else if (number <= 200) {
		cout << "between Park and Third\n";
	} else if (number <= 300) {
		cout << "between Third and Second\n";
	} else if (number <= 400) {
		cout << "between Second and First\n";
	} else if (number <= 500) {
		cout << "between First and York (or A)\n";
	} else if (number <= 600) {
		cout << "between A and B\n";
	} else {
		cerr << "street # " << number
			<< " must be in range 1 to 600 inclusive.\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
