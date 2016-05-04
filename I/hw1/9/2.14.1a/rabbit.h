//filename: rabbit.h
//Changes -> H2.14.1a
#ifndef RABBITH
#define RABBITH
#include "terminal.h"

class rabbit {
	static const char c = 'r';
	const terminal *t;
	unsigned x, y;
        //rabbit(const rabbit& another);  //H2.10c deliberately undefined 
public:
	rabbit(const terminal& initial_t, unsigned initial_x, unsigned initial_y);
        ~rabbit();
	bool move();
};
#endif
