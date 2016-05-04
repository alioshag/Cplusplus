#include <iostream>
#include <cstdlib>	//for the abs that takes and returns an int
#include <algorithm>	//for min and max
using namespace std;

int main()
{
	int i = 10;
	int j = 20;
	int sum1 = 10 + 20;	//can do arithmetic with the operators + - * /
	int sum2 = i * 30;	//can do arithmetic with variables or literals
	int a = abs(i);		//absolute value
	int m = min(i, j);	//minimum; there's also max

	//You can also write an expression in a cout statement.
	cout << i + j << "\n";

	//Multiplication has higher precedence than addition.
	cout << 1 + 2 * 3 << "\n";	//Prints 7.
	cout << (1 + 2) * 3 << "\n";	//Prints 9.

	//An example with equal precedence
	//and left-to-right associativity.
	cout << 1 - 2 + 3 << "\n";	//Prints 2.
	cout << 1 - (2 + 3) << "\n";	//Prints -4.

	int x = 10;
	int y = 20;
	int z = 30;

	//An example with equal precedence
	//and right-to-left associativity.
	z = y = x = 40;

	return EXIT_SUCCESS;
}
