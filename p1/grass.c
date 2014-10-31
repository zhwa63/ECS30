// Author: Angela(Haowen) Zhou

/* 
 * Compute the area of the grass and the time required to cut the grass.
 */ 
 
#include<stdio.h> /* printf, scanf definitions */

int
main(void)
{
 int ylen, ywid,  /* input - length and width of the yard. */ 
     hlen, hwid,  /* input - length and width of the house. */
     grass,       /* output - area of the grass. */
     min, sec;    /* output - the time required to cut the grass. */


/* Get the length and width the the yard and house. */
 printf("Please enter the length and width of the yard > ");
 scanf("%d%d", &ylen, &ywid);
 printf("Please enter the length and width of the house > ");
 scanf("%d%d", &hlen, &hwid);

/* Calculate the area of grass. */
 grass = ylen * ywid - hlen * hwid;
/* Calculate the time required. */
 min = grass/2/60;
 sec = grass/2%60;


/* Display the grass area and required time. */
 printf("%d square feet will take %d minutes and %d seconds to cut.\n", grass, min, sec);

 return(0);
}
