#ifndef WOLFH
#define WOLFH
#include "terminal.h"

class wolf {
	const terminal *t;
	unsigned x, y;
	char c;
        wolf(const wolf& another); //H2.10c deliberately undefined
public:
	wolf(const terminal& initial_t, unsigned initial_x, unsigned initial_y);
        ~wolf();
	bool move();
};
#endif
