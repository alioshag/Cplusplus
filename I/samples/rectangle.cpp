#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	//Output a 36 by 10 rectangle of Xs.

	for (int r = 0; r < 10; ++r) {		//row
		for (int c = 0; c < 36; ++c) {	//column
			cout << "X";
		}
		cout << "\n";
	}

	return EXIT_SUCCESS;
}
