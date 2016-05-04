#ifndef RABBITH
#define RABBITH
#include "terminal.h"

class rabbit {
	const terminal *t;
	unsigned x, y;
	char c;
public:
	rabbit(const terminal& initial_t, unsigned initial_x, unsigned initial_y);
	bool move();
};
#endif
