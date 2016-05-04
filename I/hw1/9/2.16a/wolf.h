//Filename: wolf.h
//Changes: H2.14.1a
#ifndef WOLFH
#define WOLFH
#include "terminal.h"

class wolf {
	static const char c = 'W';  //declaration and definition
	const terminal *const t;    //H2.17a -> pointer t is read-only and alwas pointing to the same terminal
	unsigned x, y;
        wolf(const wolf& another); //H2.10c deliberately undefined
public:
	wolf(const terminal& initial_t, unsigned initial_x, unsigned initial_y);
        ~wolf();
	bool move();
};
#endif
