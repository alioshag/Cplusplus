//reference to structure
#include <iostream>
#include <cstdlib>
using namespace std;

struct str {
        int f1;
        int f2;
};

int main()
{
        str s = {10, 20};

        s.f1 = 30;
        cout << "s.f1 == " << s.f1 << "\n";
        ++s.f1;
        cout << "++s.f1 == " << s.f1 << "\n";
        cout << "&s == " << &s << "\n";
        cout << "&s.f1 == " << &s.f1 << "\n";
        cout << "sizeof s == " << sizeof s << "\n";
        cout << "sizeof s.f1 == " << sizeof s.f1 << "\n\n\n\n";

        
        str *const p = &s;
        p->f1 = 30;
        cout << "p->f1 == " << p->f1 << "\n";
        ++p->f1;
        cout << "++p->f1 == " << p->f1 << "\n";
        cout << "p == " << p << "\n";
        cout << "&p->f1 == " << &p->f1 << "\n";
        cout << "sizeof *p == " << sizeof *p << "\n";
        cout << "sizeof p->f1 == " << sizeof p->f1 << "\n\n\n\n";


        str& r = s;
        r.f1 = 30;
        cout << "r.f1 == " << r.f1 << "\n";
        ++r.f1;
        cout << "++r.f1 == " << r.f1 << "\n";
        cout << "&r == " << &r << "\n";
        cout << "&r.f1 == " << &r.f1 << "\n";
        cout << "sizeof r == " << sizeof r << "\n";
        cout << "sizeof r.f1 == " << sizeof r.f1 << "\n\n\n\n";
        
        

        

        
        return EXIT_SUCCESS;
         
}

