#ifndef OTHERH	//If the macro OTHERH is undefined,
#define OTHERH	//define it.

//Declarations (not definitions) for variables that will be defined in one file
//and mentioned in other file(s) of the same program.

extern int moe;
extern int larry;
extern int curly;

//Dclaration (not definition) for function that will be defined in one file
//and mentioned in other file(s) of the same program.
//The keyword "extern" is unnecessary here.

extern int f(int i);

#endif
