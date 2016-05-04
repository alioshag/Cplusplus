#include <iostream>
#include <iomanip>  //for setprecision
#include <cstdlib>
using namespace std;

int main()
{
	float f =        3.14159;
	double d =       3.14159265358979;
	long double ld = 3.14159265358979323846264338327950;

	int i = 22, j = 7;
	cout << i / j << "\n";   //Integer division truncates.

	double x = 22.0, y = 7.0;
	cout << x / y << "\n\n";   //Floating point division does not truncate.
	//By default, prints 6 significant digits.

	//Output 6 significant digits.
	cout << d << "\n";

	//Output 10 digits to right of decimal point.
	cout << fixed << setprecision(10) << d << "\n\n";

	cout << setprecision(6);	//Revert to original precision.

	double avogadro = 602214179000000000000000.0;
	cout << scientific << avogadro << "\n";	//scientific notation
	return EXIT_SUCCESS;
}
