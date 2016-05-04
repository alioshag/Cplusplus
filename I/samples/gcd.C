#include <iostream>
#include <cstdlib>
#include <cassert>	//for assert
#include <algorithm>	//for min
using namespace std;

int gcd(int a, int b);

int main()
{
	const int a = 2 * 3 * 5;
	const int b =     3 * 5 * 7;

	cout << "The gcd of " << a << " and " << b << " is "
		<< gcd(a, b) << ".\n";

	return EXIT_SUCCESS;
}

int gcd(int a, int b)
{
	assert(a > 0 && b > 0);   //This expression is supposed to be true.

	int i = min(a, b);

	for (; a % i > 0 || b % i > 0; --i) {
	}

	return i;
}
