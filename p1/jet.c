//Author: Angela(Haowen) Zhou

/*
 * Calculate the acceleration and accelerate time for the jet
 */

#include<stdio.h> /* printf, scanf definitions */

int
main(void)
{
 int s; /* input - distance in meters */
 double v,      /* input - takeoff speed of the jet */
        a, t;  /* output - acceleration and time */

/* Get the speed and distance. */
 printf("Please enter the takeoff speed of the jet in km/hr > ");
 scanf("%lf", &v);
 printf("Please enter the catapult distance in meters > ");
 scanf("%d", &s);

/* Convert the speed into m/s.*/
 v = v/3600*1000;
/* Calculate the accelerated time.*/
 t = (double)(2*s)/v;
/* Calculate the acceleration.*/
 a = v/t;

/*Display the accleration and the accelerated time of the jet.*/
 printf("The jet would accelerate at %0.2lf m/s^2 for %0.2lf seconds.\n", a, t);

 return(0);
}
