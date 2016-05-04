#include <iostream>
#include <cstdlib>  //for rand, RAND_MAX
#include <ctime>    //for time
using namespace std;

int main()
{
	//Seed the random number generator.
	srand(static_cast<unsigned>(time(0)));

	for (int i = 0; i < 10; ++i) {
		cout << rand() << "\n";
	}

	return EXIT_SUCCESS;
}
