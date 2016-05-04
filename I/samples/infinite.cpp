#include <iostream>
#include <cstdlib>
#include <unistd.h>	//for sleep; Unix only
using namespace std;

int main()
{
	for (;;) {	//still need both semicolons
		cout <<
			"It was a dark and stormy night.\n"
			"Some Indians were sitting around a campfire.\n"
			"Then their chief rose and said,\n\n";

		sleep(3);
	}

	return EXIT_SUCCESS;
}
