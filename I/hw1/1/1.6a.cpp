#include <iostream>
#include <cstdlib>
using namespace std;

struct str {
        int i;
        double d;
};

int main()
{
        str a[] = {
                {10, 15.0},
                {20, 25.0},
                {30, 35.0}
        };

        const size_t n = sizeof a / sizeof a[0];

        str *p = a;
        
        cout << (*(a + 2)).d << "\n";


        cout << p[2].d << "\n";     //change the + and * operators to operator []


        cout << (p+2)->d << "\n";  //change the * to the operator ->
        
        return EXIT_SUCCESS;
}
