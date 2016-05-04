//cast to a reference
#include <iostream>
#include <cstdlib>
using namespace std;

main()
{
        short s = 0x1234;

        short *p = &s;
        cout << "*p => " << *p << "\n"
                << "p => " << p << "\n\n";
        
        
        
        cout << "&s => " << &s << "\n"
                << "*reinterpret_cast<char *>(&s) ==> " << *reinterpret_cast<char *>(&s) << "\n";
            
        cout << "&s => " << &s << "\n"
                << "reinterpret_cast<char &>(s) ==> " << reinterpret_cast<char &>(s) << "\n";
        
        
        return EXIT_SUCCESS;
}
