//p.150
//Filename: stack.h
//
#ifndef STACKH   
#define STACKH
#include <cstddef>    //for size_t

const size_t stack_max_size = 100;

class stack {
        int a[stack_max_size];
        size_t n;    //number of values currently in the stack
public:
        stack() {n = 0;}   //constructor start with the stack empty
        ~stack();

        void push(int i);
        int pop();        

        bool empty() const {return (n == 0);}   //return true if stack is empty or false if stack is not empty
        bool full() const {return (n == stack_max_size);}

        size_t size() const {return n;}
};
#endif
