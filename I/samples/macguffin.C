#include <iostream>
#include <cstdlib>
#include <cstddef>	//for size_t
using namespace std;

size_t f(int macguffin, int *a, size_t start, size_t end);

int main()
{
	int a[] = {10, 30, 20, 100, 50};
	const size_t n = sizeof a / sizeof a[0];

	const int macguffin = 100;
	const size_t i = f(100, a, 0, n);

	if (i == n) {
		cout << "Did not find " << macguffin << ".\n";
		return EXIT_FAILURE;
	}

	cout << "Found " << macguffin << " at subscript " << i << ".\n";
	return EXIT_SUCCESS;
}

size_t f(int macguffin, int *a, size_t start, size_t end)
{
	for (int i = start; i < end; ++i) {
		if (a[i] == macguffin) {
			return i;
		}
	}

	return end;
}
