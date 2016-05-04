//pass arguments by address (by reference not by value) with pointers and reference.
#include <iostream>
#include <cstdlib>
using namespace std;

void increment(int *p, int& r);

int main()
{
        int i = 10;
        int j = 20;

        increment(&i, j);
        cout << "i == " << i << "\n"
                << "j == " << j << "\n";

        return EXIT_SUCCESS;

}

void increment(int *p, int& r)
{
        ++*p;
        ++r;

}

