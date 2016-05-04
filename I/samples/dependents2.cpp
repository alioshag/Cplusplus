#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	const int deduction[] = {
		 30,    //0 dependents
		 50,    //1 dependent
		 65,    //2 dependents
		 95,    //3 dependents
		105,    //4 dependents
		120     //5 dependents
	};
	const size_t n = sizeof deduction / sizeof deduction[0];

	cout << "How many dependents do you have? ";
	int dependents;	//uninitialized variable; size_t could not hold negative
	cin >> dependents;
	if (!cin) {
		cerr << "Input failed.\n";
		return EXIT_FAILURE;
	}

	if (dependents < 0) {
		cerr << "Must be a non-negative number.\n";
		return EXIT_FAILURE;
	}

	if (dependents >= n) {
		cout << "You can deduct 124 dollars.\n";
	} else {
		cout << "You can deduct " << deduction[dependents]
			<< " dollars.\n";
	}

	return EXIT_SUCCESS;
}
