#include <iostream>
#include <cstdlib>
#include <sstream>
#include "stack.h"
using namespace std;

//Save and restore the standard error output.
static streambuf *save;
static ostringstream ostr;
inline void save_cerr() {save = cerr.rdbuf(); cerr.rdbuf(ostr.rdbuf());}
inline void restore_cerr() {cerr.rdbuf(save);}

void all_done();
bool testing_overflow = false;

int main()
{
	stack s;

	for (int i = 0; i < stack_max_size; ++i) {
		s.push(i);
	}

	if (atexit(all_done) != 0) {
		cerr << "couldn't register all_done\n";
		exit(EXIT_FAILURE);
	}

	save_cerr();
	testing_overflow = true;
	s.push(0);
	testing_overflow = false;
	restore_cerr();

	cerr << "push failed to exit when stack was already full.\n";
	return EXIT_FAILURE;
}

void all_done()
{
	if (testing_overflow) {
		cout << "Class stack passed test 3.\n";
		//Calling exit here causes infinite loop on some platforms.
	}
}
