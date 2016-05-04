#include <iostream>	//<angle brackets> mean system-wide include directory
#include <cstdlib>
#include "other.h"	//"double quotes" mean current directory
using namespace std;

/*
A compiler looks in the current directory
for header files in "double quotes".

The GNU /opt/gcc/bin/g++ compiler on i5.nyu.edu looks in the directory
/opt/gcc/include/c++/4.2.1
for header files in <angle brackets>.

The Sun /usr/bin/CC compiler on i5.nyu.edu looks in the directory
/opt/SUNWspro/prod/include/CC/Cstd
for header files in <angle brackets>.
*/

int main()
{
        cout << "moe == " << moe << "\n"
                << "larry == " << larry << "\n"
                << "curly == " << curly << "\n"
                << "f(20) == " << f(20) << "\n";

	return EXIT_SUCCESS;
}
