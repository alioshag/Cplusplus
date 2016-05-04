#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	cout << "How many electoral votes did Obama get? ";
	int obama;	//uninitialized variable
	cin >> obama;
	if (!cin) {
		cerr << "Sorry, that wasn't a number.\n";
		return EXIT_FAILURE;
	}

	cout << "How many electoral votes did McCain get? ";
	int mccain;	//uninitialized variable
	cin >> mccain;
	if (!cin) {
		cerr << "Sorry, that wasn't a number.\n";
		return EXIT_FAILURE;
	}

	if (obama == mccain) {
		cout << "They're tied.\n"
			<< "Please inform the House of Representatives "
			<< "that the Electoral College is hung.\n";
	}

	return EXIT_SUCCESS;
}
