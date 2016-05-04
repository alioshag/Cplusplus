#include <iostream>
#include <cstdlib>
using namespace std;

//A declaration announces the name and type of a variable or function
//without necessarily creating the variable or function.

//Declarations (not definitions) for global variables
//defined in some other .C file of the same program.

extern int moe;
extern int larry;
extern int curly;

/*
Declaration (not definition) for function
defined in some other .C file of the same program.
The keyword "extern" is unnecessary here.  Even without it, we can tell by the
absence of {} that this is only a declaration, not a definition.
*/

extern int f(int i);

int main()
{
        cout << "moe == " << moe << "\n"
                << "larry == " << larry << "\n"
                << "curly == " << curly << "\n"
                << "f(20) == " << f(20) << "\n";

	return EXIT_SUCCESS;
}
