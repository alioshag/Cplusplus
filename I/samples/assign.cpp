#include <iostream>
#include <cstdlib>
#include <climits>  //for INT_MAX
using namespace std;

int main()
{
	int i = 10;   //This = stands for initialization.
	cout << "The initial value of i is " << i << ".\n";

	i = 20;       //This = stands for assignment.  Assign a new value to i.
	cout << "The new value of i is (i=20) " << i << ".\n";

	i = 30 + 40;  //Can write an expression to the right of the =.
	cout << "The new value of i is (i=30+40) " << i << ".\n";

	i = i + 10;   //can also say i += 10;
	cout << "The new value of i is (i=i+10) " << i << ".\n";

	i = i + 1;    //can also say i += 1; or even ++i;
	cout << "The new value of i is (i=i+1)" << i << ".\n";

	i = INT_MAX;
	++i;          //overflow
        
        cout << "If you add 1 to INT_MAX, you get (i=INT_MAX + 1)" << i << " , INT_MAX = " << INT_MAX << "\n";

	const int stubborn = 50;
	//stubborn = 60;	//won't compile because of the keyword "const"
	return EXIT_SUCCESS;
}
