#include <iostream>
#include <cstdlib>
#include <string>	//for string
using namespace std;

int main()
{
	string a[] = {
		"Maine",
		"New Hampshire",
		"Vermont",
		"Massachusetts",
		"Rhode Island",
		"Connecticut",
		"New York",
		"New Jersey",
		"Pennsylvania",
		"Maryland",
		"Virginia",
		"North Carolina",
		"South Carolina",
		"Georgia",
		"Florida"
	};
	const size_t n = sizeof a / sizeof a[0];

	for (size_t i = n - 1; i > 0; --i) {
		for (size_t j = 0; j < i; ++j) {
			if (a[j] > a[j + 1]) {
				//Swap a[j] and a[j + 1].
				const string temp = a[j];
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
