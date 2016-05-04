#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int i = 10;	//create a variable named i of data type int
	int moe = 20, larry = 30;	//name can be more than 1 character
	int garbage;			//holds unpredictable number

	cout << i;   //Print contents of variable (in this case, the number 10)
	cout << "\n";

	cout << "i";	//Print the lowercase letter "i".
	cout << "\n";

	cout << garbage;	//unpredictable number
	cout << "\n";

	cout << "Moe and larry are ";
	cout << moe;
	cout << " and ";
	cout << larry;
	cout << ".\n";

	cout << "Moe and larry are " << moe << " and " << larry << ".\n";

	return EXIT_SUCCESS;
}
