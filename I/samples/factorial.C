#include <iostream>
#include <cstdlib>
using namespace std;

int factorial(int n);	//function declaration

int main()
{
	const int n = 4;
	cout << "The factorial of " << n << " is " << factorial(n) << ".\n";
	return EXIT_SUCCESS;
}


int factorial(int n)	//function definnition
{
	if (n <= 1) {
		return 1;
	}

	return n * factorial(n - 1);
}
