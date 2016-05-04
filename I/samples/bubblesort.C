#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int a[] = {	//our first non-const array
		1776,
		1984,
		 476,
		2001,
		   0,
		1492,
		1066,
		1999,
		  33,
		2500,
		1066,
		2007
	};
	const size_t n = sizeof a / sizeof a[0];

	for (size_t i = n - 1; i > 0; --i) {
		for (size_t j = 0; j < i; ++j) {
			//cout << "compare " << j << " " << j + 1 << "\n";
			if (a[j] > a[j + 1]) {
				//Swap a[j] and a[j + 1].
				const int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	for (size_t i = 0; i < n; ++i) {
		cout << a[i] << "\n";
	}

	return EXIT_SUCCESS;
}
