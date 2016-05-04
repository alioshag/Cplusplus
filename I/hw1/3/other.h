#ifndef OTHERH     //if macro OTHERH is undefined
#define OTHERH     //define it.
//Filename: other.h

//Declaration (not definitions) for variables that will be defined in one file
//and mentioned in other files(s) of the same program.

extern int maxx;
extern int maxy;
extern int minx;
extern int miny;


//Declaration (not definition) for functions that will be defined in one file 
//and mentioned in other files(s) of the same program.
//the key word "extern" is unnecessary here. 

extern int f(int a,int b);

#endif
