//Resolve greatest common divisor through recursion. 


#include <iostream>
#include <cstdlib>
#include <cassert>	//for assert
#include <algorithm>	//for min
using namespace std;

int gcd(int a, int b, int i);

int main()
{
	const int a = 2 * 3 * 5 *7;
	const int b =     3 * 5 * 7;

	cout << "The gcd of " << a << " and " << b << " is "
		<< gcd(a, b, min(a,b)) << ".\n";

	return EXIT_SUCCESS;
}

int gcd(int a, int b, int i)
{
	assert(a > 0 && b > 0);            //This expression is supposed to be true.

	if (a % i > 0 || b % i > 0) {
                return gcd(a, b, --i);
        }
        
        return i;
}
