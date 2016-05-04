/* div definition
filename: div.c */ 
#include <stdio.h>
#include <stdlib.h> 
#include "div.h"

//prints the quotient and the remainder of a division
void division(int divisor, int divior)
{      
        div_t resultdiv = div(divisor, divior);
        printf ("quot => %d and remainder => %d\n", resultdiv.quot, resultdiv.rem);
}


//recursive function prints the binary of decimal "num". 
void ord_binary(int num)
{
        div_t resultdiv = div(num ,2);
        printf ("quot => %d and remainder => %d\n", resultdiv.quot, resultdiv.rem);
        if (resultdiv.quot != 0) {
                ord_binary(resultdiv.quot);
        }
        printf ("printf from div.c %d\n", resultdiv.rem);
        /*return resultdiv.rem;
        return;*/
}

