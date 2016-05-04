#include <iostream>
#include <cstdlib>
#include <cfloat>   //for FLT_MIN, FLT_MAX, etc.
using namespace std;

int main()
{
	cout << "On my machine, a float occupies " << sizeof (float)
		<< " bytes and can hold " << FLT_DIG << " decimal digits.\n"
		<< "On my machine, the positive values "
		<< "that a float can hold are in the range\n"
		<< FLT_MIN << " to " << FLT_MAX << " inclusive.\n\n";

	cout << "On my machine, a double occupies " << sizeof (double)
		<< " bytes and can hold " << DBL_DIG << " decimal digits.\n"
		<< "On my machine, the positive values "
		<< "that a double can hold are in the range\n"
		<< DBL_MIN << " to " << DBL_MAX << " inclusive.\n\n";

	cout << "On my machine, a long double occupies " << sizeof (long double)
		<< " bytes and can hold " << LDBL_DIG << " decimal digits.\n"
		<< "On my machine, the positive values "
		<< "that a long double can hold are in the range\n"
		<< LDBL_MIN << " to " << LDBL_MAX << " inclusive.\n";

	return EXIT_SUCCESS;
}
