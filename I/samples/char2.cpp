#include <iostream>
#include <cstdlib>
#include <climits>  //for CHAR_MIN, CHAR_MAX
#include <cctype>   //for isprint
using namespace std;

int main()
{
        /*
        Why does this loop forever?
        for (char c = CHAR_MIN; c < CHAR_MAX; ++c) {	//test after increment
                if (isprint(static_cast<unsigned char>(c))) {
			cout << c;
		}
	}
        */

        
        for (char c = CHAR_MIN;; ++c) {	//still need both semicolons
		if (isprint(static_cast<unsigned char>(c))) {
			cout << c;
		}

		if (c == CHAR_MAX) {	//test before increment
			break;
		}
	}
	cout << "\n";
	return EXIT_SUCCESS;
}




