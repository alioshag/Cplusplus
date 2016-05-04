#include <iostream>
#include <cstdlib>
#include <cstddef>  //for size_t.  This header file is included by <iostream>
using namespace std;

int main()
{
	//Don't have to write the 12 when every element has initial value.

	const int a[12] = {
		31,	//January
		28,	//February
		31,	//March
		30,	//April
		31,	//May
		30,	//June
		31,	//July
		31,	//August
		30,	//September
		31,	//October
		30,	//November
		31	//December
	};
	const size_t n = sizeof a / sizeof a[0];

	cout << "January:  " << a[0] << "\n"
		<< "February: " <<  a[1] << "\n"
		<< "March:    " <<  a[2] << "\n"
		<< "December: " <<  a[11] << "\n"
		//cout << a[12] << "\n"	//Don't do this!

		<< "Total size in bytes: " << sizeof a << "\n"
		<< "Size in bytes of each element: " << sizeof a[0] << "\n"
		<< "Number of elements: " << n << "\n";

	for (size_t i = 0; i < n; ++i) {
		cout << a[i] << "\n";
	}
	cout << "\n";

	int sum = 0;
	for (size_t i = 0; i < n; ++i) {
		sum += a[i];	//means sum = sum + a[i]
	}

	cout << "A year has " <<  sum <<  " days.\n"
		<< "The average length of a month is "
		<< sum / static_cast<double>(n) <<  " days.\n";//don't truncate!

	int z[12] = {};	//Each element is zero.
	int g[12];	//Each element is garbage.

	return EXIT_SUCCESS;
}
