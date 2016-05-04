#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
        int i = 0;
	for (i = 0; i < 1000000000; ++i) {
             //   cout << i << "\n";
	}

        cout << i << "\n";


	//i no longer exists at this point.

	return EXIT_SUCCESS;
}
