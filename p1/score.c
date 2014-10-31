// author: Angela(Haowen) Zhou

/* 
 * Predict the score needed on a final exam to achieve a desired grade in a course.
 */

#include<stdio.h> /* printf, scanf definitons */

int
main(void)
{
 char grade;         /* input - desired grade */
 double min,current, /* input - the minimum average required and the current ave                        rage in course. */
        score;       /* output - the score needs to get on the final */
 int percent;        /* input - how much the final counts as a percentage of the                     course grade. */

/* Get the desired grade, minimum average,current average, and the percentage of the final out of the total grade. */
 printf("Enter desired grade> ");
 scanf("%c", &grade);
 printf("Enter minimum average required> ");
 scanf("%lf", &min);
 printf("Enter current average in course> ");
 scanf("%lf", &current);
 printf("Enter how much the final counts\nas a percentage of the course grade> \n");
 scanf("%d", &percent);

/* Calculate the score needs on final. */
 score=(min-current)/((double)percent/100)+current;

/* Display the final score */
 printf("You need a score of %0.2lf on the final to get a %c.\n", score,grade);

 return(0);
}
