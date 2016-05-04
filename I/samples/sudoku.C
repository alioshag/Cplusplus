#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	const size_t root = 3;
	const size_t n = root * root;	//number of rows and columns
	const int x = n;		//x stands for a missing value

	/*
	The values 0 through n-1 inclusive in this array stand for the numbers
	1 through n and will ultimately be printed as such.
	The value x stands for a blank location that hasn't been filled in yet.
	This program replaces the x in row 0 with an 8, which will ultimately
	be printed as a 9.
	*/

	int a[n][n] = {
		{0, 1, 2,	3, 4, 5,	6, 7, x},	//row 0
		{3, 4, x,	6, 7, 8,	0, 1, x},	//row 1
		{6, 7, 8,	0, 1, x,	3, 4, x},	//row 2

		{1, 2, 3,	4, 5, 6,	7, 8, x},	//row 3
		{4, 5, 6,	7, 8, 0,	1, 2, x},	//row 4
		{7, 8, x,	1, 2, x,	4, 5, x},	//row 5

		{2, 3, 4,	5, 6, 7,	8, 0, x},	//row 6
		{5, 6, 7,	8, 0, 1,	2, 3, x},	//row 7
		{x, x, x,	x, x, x,	x, x, x}	//row 8
	};

	//If there is only one missing value in row 0 (and there is,
	//in the above array), fill it in.

	/*
	The set of values that are missing from row 0.
	Initially we believe that they are all missing,
	since we have not yet examined the row.
	*/
	bool missing[n] =
		{true, true, true, true, true, true, true, true, true};

	//How many values are missing from row 0?
	size_t count = n;

	//See which values are already present in row 0.
	//Delete each value from the set of missing values.

	size_t empty_place = n;

	for (size_t col = 0; col < n; ++col) {
		const int value = a[0][col];

		if (value == x) {
			empty_place = col;       //Found an empty place.
		} else if (value < 0 || value > n) {
			cerr << "Out of range value " << value
				<< " in row " << 0 << ", column " << col
				<< ".\n";
			return EXIT_FAILURE;
		} else if (missing[value] == false) {
			cerr << "Value " << value
				<< " appears more than once in row 0.\n";
			return EXIT_FAILURE;
		} else {
			missing[value] = false;  //This value no longer missing.
			--count;
		}
	}

	//If exactly one value is missing from row 0,
	//put the missing value into the empty place in that row.

	if (count == 1) {
		for (size_t i = 0; i < n; ++i) {
			if (missing[i]) {
				a[0][empty_place] = i;
				break;
			}
		}
	}

	//Print the puzzle.

	for (size_t row = 0; row < n; ++row) {
		for (size_t col = 0; col < n; ++col) {
			if (a[row][col] == x) {
				cout << "x";
			} else {
				//add 1 for human consumption
				cout << 1 + a[row][col];
			}

			if (col < n - 1) {
				cout << (col % root == root - 1 ? "\t" : " ");
			}
		}

		cout << "\n";
		if (row < n - 1 && row % root == root - 1) {
			cout << "\n";
		}
	}

	return EXIT_SUCCESS;
}
