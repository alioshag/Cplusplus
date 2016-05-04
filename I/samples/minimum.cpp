#include <iostream>
#include <cstdlib>
#include <climits>  //for INT_MIN and INT_MAX
using namespace std;

int main()
{
 	int min = INT_MIN;	//uppercase with underscore
	int max = INT_MAX;

        
        cout << "The minimum and maximum values are " << min << " and "
		<< max << ".\n";

	cout << "The minimum and maximum values are " << INT_MIN << " and "
		<< INT_MAX << ".\n";

	//Later, we'll get the minimum and maximum values
	//from the template class numeric_limits.

	return EXIT_SUCCESS;
}
