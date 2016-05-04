//REference to a struc and pointer to a struct
#include <iostream>
#include <cstdlib>
using namespace std;

struct str {
        int f1;
        int f2;
};

void f(str copy, str *p, str& r);

main()
{
        str s = {10, 20};
        //pointer to struct
        str *const p = &s;

        cout << "The value of s.f1 is p->f1 => " << p->f1 << "\n";
        cout << "The value of ++s.f1 is ++p->f1 => " << ++p->f1 << "\n";
        cout << "The address if s is p => " << p << "\n";
        cout << "The address of s.f1 is &p->f1 => " << &p->f1 << "\n\n";
        
 
        str& r = s;
        cout << "The value of s.f1 is r.f1 => " << r.f1 << "\n";
        cout << "The value of ++s.f1 is ++r.f1 => " << ++r.f1 << "\n";
        cout << "The address if s is &r => " << &r << "\n";
        cout << "The address of s.f1 is &r.f1 => " << &r.f1 << "\n";
        
       //pass the address of a struct to a  function
        str s1 = {10, 20};
        str s2 = {30, 40};
        str s3 = {50, 60};
        
        f(s1, &s2, s3);

        cout << "The value of s1.f1 is => " << s1.f1 << "\n";
        cout << "The value of s2.f1 is => " << s2.f1 << "\n";
        cout << "The value of s3.f1 is => " << s3.f1 << "\n";
        cout << "The value of s1 is => " << &s1 << "\n";
        //cout << "The value of s2 is => " << s2 << "\n";
        //cout << "The value of s3 is => " << s3 << "\n";

        
        
        return EXIT_SUCCESS;
}
void f(str copy, str *p, str& r)
{
        ++copy.f1;    //passed by value
        ++p->f1;
        ++r.f1;
}

