#include <iostream>
#include <cstdlib>   //for exit function
#include "wolf.h"
using namespace std;

wolf::wolf(const terminal& initial_t, unsigned initial_x, unsigned initial_y)
{
	t = &initial_t;
	x = initial_x;
	y = initial_y;
	c = 'W';

        //lines added by AG
        if (!t->in_range(x ,y)) {
                cerr << "Initial wolf position (" << x << ", " << y
                        << ") off " << t->xmax() << " by " << t->ymax()
                        << " terminal.\n";
                exit(EXIT_FAILURE);
        }

        const char other = t->get(x, y);
        const char background = t->background();

        if (other != background) {
                cerr << "Initial wold position (" << x << ", " << y
                        << ") already occupied by '" << other << "'.\n";
                exit(EXIT_FAILURE);
        }

        if (c == background) {
                cerr << "Rabbit character '" << c << "' can't be the same as "
                        "the terminal's backgraound character.\n";
                exit(EXIT_FAILURE);
        }

        t->put(x, y, c);
	//Copy lines 13-35 of the above rabbit.C here,
	//changing the word "rabbit" to "wolf".
}

//Wolf Destructor 2.10b
wolf::~wolf()
{
        t->beep();      //Beep the terminal on which the animal is dying
        
        t->wait(1000);    //Pause a second
        
        //when animal died, erase the animal from the screen and replaced it with background char.
        if (t->get(x, y) == c) {    //compare if position of animal on terminal is the animal char
                t->put(x, y);       //is true? call the default put function (with background char "." (omited)
        }
        cout << "Destructor for Wolf\n"; 
}

//Return false if this wolf ate another animal, true otherwise.

bool wolf::move()
{
	struct keystroke {
		char c;
		int dx;   //horizontal difference
		int dy;   //vertical difference
	};

	static const keystroke a[] = {
		{'h',   -1,    0},   //left
		{'j',    0,    1},   //down
		{'k',    0,   -1},   //up
		{'l',    1,    0}    //right
	};
	static const size_t n = sizeof a / sizeof a[0];

	if (const char k = t->key()) {
		for (const keystroke *p = a; p < a + n; ++p) {
			if (k == p->c) {
				const unsigned newx = x + p->dx;
				const unsigned newy = y + p->dy;

				if (!t->in_range(newx, newy)) {
					break;         //Go to line 57.
				}

				const bool I_ate_him =
					t->get(newx, newy) != t->background();

				t->put(x, y);      //Erase this wolf from its old location.
				x = newx;
				y = newy;
				t->put(x, y, c);   //Redraw this wolf at its new location.

				return !I_ate_him;
			}
		}

		//Punish user who pressed an illegal key or tried to move off screen.
		t->beep();
	}

	return true;
}
