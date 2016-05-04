#include <iostream>
#include <cstdlib>
#include <sstream>
#include "stack.h"
using namespace std;

//Save and restore the standard error output.
static ostringstream ostr;
static streambuf *save;
inline void save_cerr() {save = cerr.rdbuf(); cerr.rdbuf(ostr.rdbuf());}
inline void restore_cerr() {cerr.rdbuf(save);}

void all_done();
bool testing_underflow = false;

int main()
{
	if (atexit(all_done) != 0) {
		cerr << "couldn't register all_done\n";
		exit(EXIT_FAILURE);
	}

	save_cerr();
	testing_underflow = true;
	stack().pop();
	testing_underflow = false;
	restore_cerr();

	cerr << "pop failed to exit when stack was already empty.\n";
	return EXIT_FAILURE;
}

void all_done()
{
	if (testing_underflow) {
		cout << "Class stack passed test 4.\n";
		//Calling exit here causes infinite loop on some platforms.
	}
}
