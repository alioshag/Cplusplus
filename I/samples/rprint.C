#include <iostream>
#include <cstdlib>
using namespace std;

void print(int start);

int main()
{
	print(1);	//Print the integers from 1 to 10 inclusive.
	return EXIT_SUCCESS;
}


void print(int start)   //Print the integers from start to 10 inclusive.
{
	cout << start << "\n";		//Do the first part of the job.

	if (start < 10) {		//If part of the job remains undone,
		print(start + 1);	//do the rest of the job.
	}
}
