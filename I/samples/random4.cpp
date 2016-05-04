#include <iostream>
#include <cstdlib>  //for EXIT_SUCCESS, rand, srand, RAND_MAX
#include <ctime>    //for time
using namespace std;

int main()
{
	srand(static_cast<unsigned>(time(0)));

	//Output random double's in the range 0.0 to 1.0 inclusive.

	for (int i = 0; i < 10; ++i) {
		cout << rand() / static_cast<double>(RAND_MAX) << "\n";
	}

	return EXIT_SUCCESS;
}
