#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	cout << "27 / 6 = " << 27 / 6 << "\n";	//quotient: prints 4, not 4.5
	cout << "27 % 6 = " << 27 % 6 << "\n";	//remainder: prints 3

	//We have just discovered that 27 beers
	//are 4 six packs plus 3 extra bottles.

	cout << "28 % 6 = " << 28 % 6 << "\n";	//prints 4
	cout << "29 % 6 = " << 29 % 6 << "\n";	//prints 5
	cout << "30 % 6 = " << 30 % 6 << "\n";	//prints 0

	//On some machines, quotient is -4 and remainder is -5.
	//On others, quotient is -5 and remainder is 1.
	cout << "-29 / 6 = " << -29 / 6 << "\n";
	cout << "-29 % 6 = " << -29 % 6 << "\n";

	cout << flush;	//Flush the output buffer before the program crashes.

	cout << "29 / 0 = " << 29 / 0 << "\n";	//unpredictable behavior: what exit status?
	cout << "29 % 0 = " << 29 % 0 << "\n";	//unpredictable behavior
	return EXIT_SUCCESS;
}
