/*****************
 * filename: test.cpp
 * snopsis: forward declaration of function
 * ***********************/

#include <iostream>
using std::cout;
//using std::string

char* myfunction(char* n) {return n;}

int main()
{
        cout << "the argument is: " << myfunction("name") << "\n";
        return 0;
}
