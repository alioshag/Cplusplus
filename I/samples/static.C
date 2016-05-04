#include <iostream>
#include <cstdlib>
using namespace std;

void f();

int main()
{
	f();
	f();
	f();

	return EXIT_SUCCESS;
}

void f()
{
	//The = 0 is performed only the first time the function is called.
	static int i = 0;

	++i;
	cout << "This is the " << i;

	if (11 <= i % 100 && i % 100 <= 13) {
		cout << "th";
	} else if (i == 1) {
		cout << "st";
	} else if (i == 2) {
		cout << "nd";
	} else if (i == 3) {
		cout << "rd";
	} else {
		cout << "th";
	}

	cout << " call to the function.\n";
}
