#include <iostream>
#include <cstdlib>
#include "terminal.h"
using namespace std;

int main()
{
	const terminal term('.'); //The constructor for term calls term_construct.

	const unsigned xmax = term.xmax();
	const unsigned ymax = term.ymax();

	unsigned x = xmax / 2;	    //center of screen
	unsigned y = ymax / 2;

	term.put(x, y, 'X');
	char c = term.get(x, y);
	term.next(x, y);
	term.put(x, y, c);

	term.put(0, 0, "Please type printable characters ending with a q.");

	for (x = 0, y = 1; term.in_range(x, y); term.next(x, y)) {
		while ((c = term.key()) == '\0') {
		}

		if (c == 'q') {         //quit
			break;
		}

		term.put(x, y, c);
	}

	term.wait(1000);
	term.beep();
	return EXIT_SUCCESS;      //The destructor for term calls term_destruct.
}
