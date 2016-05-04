/*************************************************************************************
 *[File: /home/agonzale/code/samples/floating/floating.c]
 *
 * Floating and integer use and test
 *
 *
 *
 * **************************************************************************************/

#include <stdio.h>

int integer; /* an integer */ 
float floating; /* floating point number */

int main ()
{
        floating = 1.0 / 2.0;        /* assign floating 0.5 */
        
        printf("floating = 1.0 / 2.0 = %f\n", floating); 

        integer = 1 / 3;             /* Assing integer 0 */
        printf("integer = 1 / 3 = %d\n", integer);  
        
        floating = (1 / 2) + (1 / 2); /* assign floating 0 */
        printf("floating = (1 / 2) + (1 / 2) = %f\n",floating);
        
        floating = 3.0 / 2.0;        /* assign floating 1.5 */
        printf("floating = 3.0 / 2.0 = %f\n", floating);
        
        integer = floating;          /*assign integer 1 */
        printf("integer = floating = %d\n", integer);
        return (0);
}
