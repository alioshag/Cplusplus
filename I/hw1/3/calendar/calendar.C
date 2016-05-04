//calendar.C
#include "calendar.h"
	
//defines and initializes the array with each month of the calendar
extern const int length[] = {
		 0,   //dummy element so that January will have subscript 1
		31,   //January
		28,   //February
		31,   //March
		30,   //April
		31,   //May
		30,   //June
		31,   //July
		31,   //August
		30,   //September
		31,   //October
		30,   //November
		31    //December
	};



//defines the functions 
int fdistance_yrs(int distance)
{
        return distance / 365;
}
int fdistance_days(int distance)
{
        return distance % 365;
}

