#include <iostream>
#include <cstdlib>
using namespace std;

struct str {
        int f1;
        int f2;
};



main ()
{
        str s = {10, 20};
        
        s.f1 = 30;
        str *const p = &s;
        str& r = s;

        ++s.f1; ++p->f1; ++r.f1;
        
        cout << "value of s.f1 => " << s.f1 << "\n" 
                << "p->f1 => " << p->f1 << "\n"
                << "r.f1 => " << r.f1 << "\n";

        cout << "address of &s => " << &s << "\n"
                << "p => " << p << "\n"
                << "r => " << &r << "\n";
        
        cout << "address of &s.f1 => " << &s.f1 << "\n"
                << "&p->f1 => " << &p->f1 << "\n"
                << "&r.f1 => " << &r.f1 << "\n";

        cout << sizeof s << sizeof *p << sizeof r << "\n";
        cout << sizeof s.f1 << sizeof p->f1 << sizeof r.f1 << "\n";



        
        return EXIT_SUCCESS;
}
