//Return the address of a variable from a function
#include <iostream>
#include <cstdlib>
using namespace std;

int i = 30;
int *g();
int& h();

main()
{
        *g() = 20;
        
        cout << "the value of i is *g() => " << *g() << "\n";
        cout << " the address of i is g() => " << g() << "\n";

        h() = 40;
        cout << "the value of i is h() => " << h() << "\n";
        cout << "the address of i is &h() => " << &h() << "\n";

        return EXIT_SUCCESS;
}

int *g()
{
        return &i;
}

int& h()
{
        return i;
}

