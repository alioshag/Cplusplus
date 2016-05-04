#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int i;	//uninitialized variable

	for (i = 0; i < 10; ++i) {
		cout << i << "\n";
	}

	//i still exists at this point, but there is no need for it to do so.

	return EXIT_SUCCESS;
}
