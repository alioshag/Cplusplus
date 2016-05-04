#include <iostream>
#include <cstdlib>
#include <cmath>	//for pow
using namespace std;

int main()
{
	//Set of organ pipes spanning one octave.
	//setprecision would make the output look less ragged.

	const double factor = pow(2, 1.0/12.0);	//twelfth root of 2
	double length = 100;

	for (int i = 0; i <= 12; ++i) {
		cout << i << "\t" <<  length << "\n";	//tab
		length *= factor;              //means length = length * factor;
	}

	cout << "factor == " << factor << "\n";
	return EXIT_SUCCESS;
}
