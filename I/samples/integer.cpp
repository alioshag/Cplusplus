#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	/*
	Data types for holding signed integers
	(i.e., integers that could be negative).
	Can say "short" instead of "short int"; "long" instead of "long int".

	The cast should really be the following, to avoid sign extension.
	static_cast<unsigned>(static_cast<unsigned char>(c))

	The minimum and maximum values on my machine are:
	*/

	signed char c = 65;		//-128 to 127
	short int s = 1000;		//-32,768 to 32,767
	int i = 1000000000;		//-2,147,483,648 to 2,147,483,647
	long int lo = 1000000000;	//-2,147,483,648 to 2,147,483,647

	cout << "c == " << c << "\n"	//Output the character whose code is 65
		<< "c == " << static_cast<int>(c) << "\n" //Output 65 in decimal.
		<< "s == " << s << "\n"
		<< "i == " << i << "\n"
		<< "lo == " << lo << "\n";

	return EXIT_SUCCESS;
}
