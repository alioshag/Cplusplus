#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	for (char c = 'A'; c <= 'Z'; ++c) {
		cout << c;
	}
	cout << "\n\n";

	/*
	Print all the printable characters,
	assuming that the character set is ASCII.
	' ' is the printable character with the smallest ASCII code (32).
	'~' is the printable character with the largest ASCII code (126).
	*/

	for (char c = ' '; c <= '~'; ++c) {
		cout << c;
	}
	cout << "\n";

	return EXIT_SUCCESS;
}
