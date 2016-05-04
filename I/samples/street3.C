#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	const size_t n = 7;
	const string avenue[][n] = {
		{"5th", "Park/4th", "3rd", "2nd", "1st", "York/A", "B"},
		{"5th", "6th",      "7th", "8th", "9th", "10th", "11th"}
	};

	int side = 1;	//0 for East, 1 for West
	int street = 42;
	int number = 100;

	if (number < 1 || number > (n - 1) * 100) {
		cerr << "street # " << number << " must be in range 1 to "
			<< (n - 1) * 100 << " inclusive.\n";
		return EXIT_FAILURE;
	}

	const size_t a = (number - 1) / 100;

	cout << "between " << avenue[side][a]
		<< " and " << avenue[side][a + 1] << "\n";
	return EXIT_SUCCESS;
}
