#include <iostream>
#include <cstdlib>	//for srand and rand
#include <ctime>	//for time
using namespace std;

//rand returns an int in the range 0 to RAND_MAX inclusive.

int main()
{
	srand(static_cast<unsigned>(time(0)));
	const size_t n = 10;
	int a[n];	//could initialize to all zeroes with = {};

	cout << "RAND_MAX == " << RAND_MAX << "\n";

	for (size_t i = 0; i < n; ++i) {
		a[i] = 0;
	}
        cout << "after array initialized with all zeros \n";
	for (int i = 0; i < 1000000; ++i) {

		//r is in the range 0 to n-1 inclusive.
		//Without the + 1, r would be in the range 0 to n inclusive,
		//which is too big to be a subscript for our array.

		const size_t r = n * rand() / (RAND_MAX + 1);
		++a[r];
	}

	for (size_t i = 0; i < n; ++i) {
		cout << a[i] << "\n";
	}

	return EXIT_SUCCESS;
}
