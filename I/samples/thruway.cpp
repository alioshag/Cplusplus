#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	for (int a = 98; a >= 38; a -= 10) {	//a -= 10 means a = a - 10
		cout
			<< "+--------------+\n"
			<< "| Albany    " << a << " |\n"
			<< "| Montreal " << a + 300 << " |\n"
			<< "| Buffalo  " << a + 360 << " |\n"
			<< "+--------------+\n\n";
	}

	return EXIT_SUCCESS;
}
