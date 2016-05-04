#include <iostream>
#include <cstdlib>
using namespace std;

void print(int start, int end);

int main()
{
	print(1, 12);	//Print the integers from 1 to 12 inclusive.
	return EXIT_SUCCESS;
}


void print(int start, int end)//Print the integers from start to end inclusive.
{
	if (start > end) {
		cerr << "start " << start << " can't be bigger than end " << end
			<< "\n";
		exit(EXIT_FAILURE);
	}

	cout << start << "\n";

	if (start < end) {
		print(start + 1, end);
	}
}
