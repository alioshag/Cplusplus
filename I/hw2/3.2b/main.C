#include <iostream>
#include <cstdlib>
#include "date.h"
using namespace std;

int main(int argc, char **argv)
{
	const int day[] = {10, 20};
	const date::month_type month[] = {date::january, date::february};
	const int year[] = {2000, 2001};

	const size_t scramble[][2] = {
		{0, 1},
		{0, 0},
		{1, 0}
	};
	const size_t n = sizeof scramble / sizeof scramble[0];

	for (size_t y = 0; y < n; ++y) {
		for (size_t m = 0; m < n; ++m) {
			for (size_t d = 0; d < n; ++d) {
				const int y0 =  year[scramble[y][0]];
				const int m0 = month[scramble[m][0]];
				const int d0 =   day[scramble[d][0]];

				const int y1 =  year[scramble[y][1]];
				const int m1 = month[scramble[m][1]];
				const int d1 =   day[scramble[d][1]];

				const bool b = y0 < y1 || y0 == y1 &&
					(m0 < m1 || m0 == m1 && d0 < d1);

				if (date(m0, d0, y0) < date(m1, d1, y1) != b) {
					cout << "Your operator< returns the wrong result.\n"
						<< m0 << "/" << d0 << "/" << y0
						<< " should ";
					if (!b) {
						cout << "not ";
					}
					cout << "be less than "
						<< m1 << "/" << d1 << "/" << y1
						<< ".\n";
					return EXIT_FAILURE;
				}
			}
		}
	}

	cout << "operator< passed all tests.\n";
	return EXIT_SUCCESS;
}
