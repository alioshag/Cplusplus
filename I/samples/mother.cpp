#include <iostream>
#include <cstdlib>
#include <string>	//for string
using namespace std;

int main()
{
	cout << "What would you like to eat? ";
	string food;	//looks uninitialized, but initialized to empty string
	cin >> food;

	if (!cin) {
                cerr << "Sorry, couldn't input the string.\n";
                return EXIT_FAILURE;
        }

	cout << "You can't have that because it ";

	if (food.find("sugar") == string::npos) {
		cout << "turns to sugar in your stomach.\n";
	} else {
		cout << "has sugar in it.\n";
	}

	cout << "Incidentally, \"" << food << "\" is " << food.size()
		<< " character(s) long.\n";

	return EXIT_SUCCESS;
}
