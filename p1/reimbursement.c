//Author: Angela(Haowen) Zhou


/* 
 * Calculate mileage reimbursement for a salesperson at a rate of $.35 per mile. */

#include<stdio.h> /* printf, scanf definitons */
#define RATE .35

int
main(void)
{
 double begin,end,       /* input - the beginning and ending odometer reading */
        distance,reim;   /* output - the miles and reimbursement */

/* Get the beginning and ending odometer reading */
 printf("MILEAGE REIMBURSEMENT CALCULATOR\n");
 printf("Enter beginning odometer reading=> ");
 scanf("%lf", &begin);
 printf("Enter ending odometer reading=> ");
 scanf("%lf", &end);


/* Compute the miles traveled */
 distance = end-begin;

/* Display the traveled distance in mile */
printf("You traveled %.1lf miles. At $.35 per mile,\n", distance);


/* Compute the reimursement at $.35 per mile */
reim=distance*RATE;


/* Display the reimbursement */
printf("your reimbursement is $%.2lf.\n", reim);

return(0);
}
