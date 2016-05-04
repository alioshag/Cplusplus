#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	const int january   = 31; 	//all the same data type
	const int february  = 28;
	const int march     = 31;
	const int april     = 30;
	const int may       = 31;
	const int june      = 30;
	const int july      = 31;
	const int august    = 31;
	const int september = 30;
	const int october   = 31;
	const int november  = 30;
	const int december  = 31;

	const int sum = january + february + march + april + may + june
		+ july + august + september + october + november
		+ december;

	cout << "A year has " << sum << " days.\n"
		<< "The average length of a month is "
		<< sum / 12.0 << " days.\n";	//.0 avoids truncation!

	return EXIT_SUCCESS;
}
