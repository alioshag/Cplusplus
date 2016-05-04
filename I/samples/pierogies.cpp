#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	for (int h = 2; h <= 8; ++h) {
		cout << 4 * h << " pierogies feed "
			<< 2 * h << " people or "
			<< h << " Hungarians.\n";
	}

	return EXIT_SUCCESS;
}
