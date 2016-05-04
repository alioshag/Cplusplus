#include <iostream>
#include <cstdlib>
#include <climits>  //for INT_MAX
using namespace std;

int main()
{
	int n;	//uninitialized variable
        
        do {
                cout << "Please type an integer in range 2 to " << INT_MAX
                     << " inclusive: ";
                cin >> n;
                if (!cin) {
                        cerr << "Sorry, that wasn't a number, or was out of range.\n";
                        return EXIT_FAILURE;
                }
        } while (n < 2);
        

	for (int i = 2; i < n; ++i) {
		if (n % i == 0) {	//if n is divisible by i
			cout << n << " is not prime; it is divisible by "
				<< i << ".\n";
			return EXIT_SUCCESS;
		}
	}

	cout << n << " is prime.\n";
	return EXIT_SUCCESS;
}
