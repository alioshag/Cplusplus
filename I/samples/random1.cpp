#include <iostream>
#include <cstdlib>  //for rand, RAND_MAX, EXIT_SUCCESS
using namespace std;

int main()
{
	cout << "RAND_MAX == " << RAND_MAX << "\n\n";

	//Output random int's in the range 0 to RAND_MAX inclusive.

	for (int i = 0; i < 10; ++i) {
		cout << rand() << "\n";
	}

	return EXIT_SUCCESS;
}
