#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	double d = 3.6;
	//Cause truncation (not rounding):
	cout << static_cast<int>(d) << "\n";

	int i = 22;
	int j = 7;

	//Prevent truncation:
	cout << i / j << "\n"				//outputs 3
//		<< i / static_cast<double>(j) << "\n";	//outputs 3.14286
                << static_cast<double>(i) / j << "\n";  //same
	return EXIT_SUCCESS;
}
