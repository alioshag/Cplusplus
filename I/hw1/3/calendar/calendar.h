//calendar.h
#ifndef CALENDARH
#define CALENDARH

//Declaration of variables that will be defined in one file and mentioned in other files of the same program

//the size of the array must by provided for the use of sizeof later in the program
extern const int length[13];    //define in calendar.C

//Function declaration (not definition)
extern int fdistance_yrs(int distance);
extern int fdistance_days(int distance);


#endif
