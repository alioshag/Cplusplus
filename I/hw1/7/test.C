#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char **argv)
{
        cout << "The size of int => " << sizeof (int) << "\n";
        cout << "The size of long type var is => " << sizeof (long) << "\n";
        cout << "The size of double is => " << sizeof (double) << "\n";
        cout << "int argc => " << argc << "\n";
        cout << "char argv[0] => " << argv[0] << "\n";
        cout << "char argv[1] => " << argv[1] << "\n";
        

        return EXIT_SUCCESS;
}

