#include <iostream>      //<angle brackets> mean system-wide include directory
#include <cstdlib>
#include "other.h"       //"double quotes" mean current directory
using namespace std;

int main()
{
        cout << "maxx = " << maxx << "\n"
                << "maxy = " << maxy << "\n"
                << "minx = " << minx << "\n"
                << "miny = " << miny << "\n"
                << "f(20,30) = " << f(20,30) << "\n";

        return EXIT_SUCCESS;
}
