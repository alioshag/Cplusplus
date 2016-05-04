#include <iostream>
#include <cstdlib>
#include "date.h"
using namespace std;

int main()
{
	//date d1(12,10,2012);
	//date d1;
	date d1(12,31,2012);
	date d2;

	if (d1 == d2) {
		cout << "They're the same date.\n";
	} 
        if (d1 < d2) {
                cout << "d1 < d2.\n";
        }
        if (d1 > d2) {
                cout << "d1 > d2.\n";
        }
        if (d1 >= d2) {
                cout << "d1 >= d2.\n";
        }
        if (d1 <= d2) {
                cout << "d1 <= d2.\n";
        }
	return EXIT_SUCCESS;
}
