//Filename main.C
//Description: uses the functions push and pop for a stack
//
#include <iostream>
#include <cstdlib>
using namespace std;
#include "stack.h"

int main()
{
        cout << "type in the SS to add a new person\n" 
                << "type a zero to pop the last persons SS\n"
                << "type a negative number to quit\n";
        
        //::stack s;      //calls the constructor for s with no arguments

        for (::stack s;;) {            //here, the object will last only till the end of the loop.
              int ss;
              cin >> ss;
              if (ss < 0) {     //quit
                      break;
              }
              if (ss > 0) {
                      s.push(ss);
              } else {               //firei
                      cout << " The firing number is => " << s.pop() << "\n";
              }
        }
        
        return EXIT_SUCCESS;  //call the destructor for s.
}
