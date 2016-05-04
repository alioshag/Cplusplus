#ifndef WOLFH
#define WOLFH
#include "terminal.h"

class wolf {
	const terminal *t;
	unsigned x, y;
	char c;
public:
	wolf(const terminal& initial_t, unsigned initial_x, unsigned initial_y);
	bool move();
};
#endif
