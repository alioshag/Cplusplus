#include <iostream>
#include <cstdlib>
using namespace std;

//Global variables can be mentioned in all the functions below them
//in the same file.

int score = 10;
int i = 20;

void f();

int main()
{
	cout << "in main, score == " << score << "\n";

	int i = 30;
	cout << "in main, i == " << i << "\n";		//the local i
	cout << "in main, ::i == " << ::i << "\n";	//the global i

	f();
	return EXIT_SUCCESS;
}

void f()
{
	cout << "in f, score == " << score << "\n";
}
