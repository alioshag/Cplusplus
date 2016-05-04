//Filename: terminal.h
//Changes: H2.14.2a p244  -> Made member function beep static
//         H2.17b p269 -> Make the data members of the class terminal const since its members functions do not change them
#ifndef TERMINALH
#define TERMINALH

extern "C" {
#include "term.h"
}

class terminal {
	const char _background;   //default value for third argument of put
	const unsigned _xmax;     //number of columns of characters
	const unsigned _ymax;     //number of rows of characters

	void check(unsigned x, unsigned y) const;
public:
	terminal(char initial_background = ' '); //default arg value if nothing is passed
	~terminal();
        //These member functions provide public read-only access
	char background() const {return _background;}
	unsigned   xmax() const {return _xmax;}
	unsigned   ymax() const {return _ymax;}

	void put(unsigned x, unsigned y, char c) const;
	void put(unsigned x, unsigned y) const {put(x, y, _background);}
	void put(unsigned x, unsigned y, const char *s) const;
	char get(unsigned x, unsigned y) const {check(x, y); return term_get(x, y);}

	char key() const {return term_key();}
	void wait(int milliseconds) const {term_wait(milliseconds);}
	//void beep() const {term_beep();}
	static void beep() {term_beep();}

	bool in_range(unsigned x, unsigned y) const {return x < _xmax && y < _ymax;}
	void next(unsigned& x, unsigned& y) const;
};
#endif
