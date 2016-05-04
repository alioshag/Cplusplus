#include <iostream>
#include <cstdlib>  //for rand, RAND_MAX
#include <ctime>    //for time
using namespace std;

int main()
{
	srand(static_cast<unsigned>(time(0)));

	//Output random ints in the range 0 to 99 inclusive.
	for (int i = 0; i < 10; ++i) {
		cout << rand() % 100 << "\n";
	}
	cout << "\n";

	//Output random ints in the range 1 to 100 inclusive.
	for (int i = 0; i < 10; ++i) {
		cout << rand() % 100 + 1 << "\n";
	}
	cout << "\n";

	return EXIT_SUCCESS;
}
