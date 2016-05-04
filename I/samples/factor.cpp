#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	cout << "What positive integer do you want to factor? ";
	int n;	//uninitialized variable
	cin >> n;

	for (int factor = 2; factor <= n; ++factor) {

		/*
		n % factor == 0 keeps it looping as long as n is divisible by
		factor.
		n /= factor means n = n / factor
		*/

		for (; n % factor == 0; n /= factor) {
			cout << factor << "\n";
		}
	}

	return EXIT_SUCCESS;
}
