//Filename stack.C
//Description: Declaration of push and pop functions
//
#include <iostream>
#include <cstdlib>
#include "stack.h"
using namespace std;

stack::~stack() //destructor
{
        if (!empty()) {
                cerr << "Warning: stack still contains " << size() << " values\n";
        }
}
void stack::push(int i)        //puts a value into the stack
{
        if (full()) {
                cerr << "Can't push when size " << size() << " == capacity " << stack_max_size << "\n";
                exit(EXIT_FAILURE);
        }
        a[n++] = i;
}
int stack::pop()            //pops a value from the stack
{
        if (empty()) {
                cerr << "Can't pop when size of n == " << size() << "\n";
                exit(EXIT_FAILURE);
        }
        return a[--n];
}
