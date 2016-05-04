/******************************************************************
   [File: term/term.c]
 * term program to test the use of printf * 
 *
 *
 ******************************************************************/

#include <stdio.h>
int term;         /* term use in two expression */
int term_2;       /* twice term */
int term_3;       /* three times term */

int main()
{
        term = 3 * 5;
        term_2 = 2 * term;
        term_3 = 3 * term;

        printf("Twice %d is %d\n", term, term_2);
        printf("Three %d is %d\n", term, term_3);
        return (0);
}

