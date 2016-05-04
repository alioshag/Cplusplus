#include <iostream>	//for cin, cout, clear, ignore, <<, >>
#include <cstdlib>
#include <climits>	//for INT_MAX
using namespace std;

int main()
{
	cout << "Please type a number and press RETURN:\n";
	int i;	//uninitialized variable: born with an unpredictable value.
	cin >> i;

	if (!cin) {   //if cin is unhealthy (the exclamation point means "not")
		//Arrive here of the previous attempt at input failed.
		cerr << "Sorry, that wasn't a number.\n";
		return EXIT_FAILURE;
        }	

	cout << "Please type another number and press RETURN:\n";
	int j;	//uninitialized variable
	cin >> j;

	if (!cin) {
		cerr << "Sorry, that wasn't a number.\n";
		return EXIT_FAILURE;
	}

	cout << "The sum of " << i << " and " << j << " is " << i + j << ".\n";
	return EXIT_SUCCESS;
}
