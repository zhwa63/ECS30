//Author: Angela(Haowen) Zhou

/* 
 * Calculate the three sides of a Pythagorean triple.
 */

#include<stdio.h>  /* printf, scanf definitons */

int
main(void)
{
 int m, n, /* input - two sides of a right triangle. */
     side1, side2, hypo; /* output - three sides of the Pythagorean triple.*/


/* Get the two sides of the right triangle. */
 printf("Please enter two integers with the first larger than the second > ");
 scanf("%d%d", &m, &n);


/* Calculate the first side of the Pythagorean triple. */
 side1 = m*m - n*n;
/* Calculate the second side of the Pythagorean triple. */
 side2 = 2*m*n;
/* Calculate the hypotenuse of the Pythagorean triple. */
 hypo = m*m+n*n;


/* Display the three sides of the Pythagorean triple. */
 printf("The Pythagorean triple of %d and %d is %d, %d, and %d.\n", m,n,side1, side2, hypo);

 return(0);
}
