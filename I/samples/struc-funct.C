//pass the addr of a struct to a function
#include <iostream>
#include <cstdlib>
using namespace std;

struct str {
        int f1;
        int f2;
};

void f(str copy, str *p, str& r);

int main()
{
        str a1 = {10, 20};
        str a2 = {10, 20};
        str a3 = {10,20};

        f(a1, &a2, a3);
        cout << "a1.f1 => " << a1.f1 << "\n"
                << "a2.f1 => " << a2.f1 << "\n"
                << "a3.f1 => " << a3.f1 << "\n";

        f(a1, &a2, a3);
        cout << "address of a1.f1 => " << &a1.f1 << "\n"
                << "&a2.f => " << &a2.f1 << "\n"
                << "&a3.f1 => " << &a3.f1 << "\n";
        
        return EXIT_SUCCESS;
}

void f(str copy, str *p, str& s)
{
        ++copy.f1;
        ++p->f1;
        ++s.f1;
}

