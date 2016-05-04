#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	for (int b = 100; b >= 1; --b) {	//--b means b = b - 1
		cout
			<< b << " bottles of beer on the wall,\n"
			<< b << " bottles of beer--\n"
			<< "If one of those bottles should happen to fall,\n"
			<< b - 1 << " bottles of beer on the wall\n\n";
	}

	return EXIT_SUCCESS;
}
