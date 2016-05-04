#include <iostream>
#include <cstdlib>
#include <string>	//for string
using namespace std;

int main()
{
	const string a[] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	const size_t n = sizeof a / sizeof a[0];

	cout << "Name of each month:\n";
	for (size_t i = 0; i < n; ++i) {
		cout << a[i] << "\n";
	}

	return EXIT_SUCCESS;
}
