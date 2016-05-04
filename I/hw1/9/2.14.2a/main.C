//filename: main.C (the rabbit game)
//Changes -> 11/27/2012: instead of one rabbit, now we have an array of 6 rabbits
//
#include <cstdlib>   //for the srand function and EXIT_SUCCESS
#include <ctime>     //for the time function

#include "terminal.h"
#include "wolf.h"
#include "rabbit.h"

using namespace std;

int main()
{
	srand(static_cast<unsigned>(time(0)));
	const terminal term('.');

	const unsigned xmax = term.xmax();
	const unsigned ymax = term.ymax();

	wolf   w(term, xmax * 1 / 3, ymax / 2);
	//rabbit r(term, xmax * 2 / 3, ymax / 2);

        rabbit a[] = {
                rabbit(term, xmax * 2 / 3, ymax / 2),
                rabbit(term, xmax * 2 / 3, ymax / 5),
                rabbit(term, xmax * 2 / 3, ymax / 7),
                //rabbit(term, xmax * 2 / 5, ymax / 2),
                //rabbit(term, xmax * 2 / 7, ymax / 5),
                //rabbit(term, xmax * 2 / 9, ymax / 7)
        };
        const size_t n = sizeof a / sizeof a[0];
        
	for (;; term.wait(250)) {   //250 milliseconds equals .25 seconds
		if (!w.move()) {
			goto done;
		}
                for (rabbit *p = a; p < a + n; ++p) {
                        if (!p->move()) {
                                goto done;
                        }
		}
	}

        done:;

	term.put(0, 0, "You killed a rabbit!");
	term.wait(3000);     //Give user three seconds to read the message.
	return EXIT_SUCCESS; //Destruct rabbit, wolf, & terminal, in that order.
}
