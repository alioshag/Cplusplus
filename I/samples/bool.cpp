#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	bool b = false;	//or true
	cout << b << "\n"
		<< boolalpha << b << noboolalpha << "\n";

	int i = 10;
	int j = 20;

	/*
	Save the relationship of i and j for later use.
	Parentheses unnecessary: even without them, the < would execute
	before the = because < has higher precedence.
	*/

	b = (i < j);
	cout << "b == " << b << "\n";

	//The following if's would normally be combined into an if-else.
	//I just wanted to demonstrate the exclamation point.

	if (b) {
		cout << "i was less than j.\n";
	}

	if (!b) {   //! means "not".
		cout << "i was not less than j.\n";
	}

	b = !b;     //toggle the value: ! means "The opposite of"
	return EXIT_SUCCESS;
}
