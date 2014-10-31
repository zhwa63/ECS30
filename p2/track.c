//Author: Angela(Haowen) Zhou

#include<stdio.h>
#define FT_IN_MILE 5280
#define FT_IN_KM 3282

void instrction(void);

int main()
{
 int min;
 double sec, totsec, ftps, mps;

 instruction();

 printf("Minutes for the runner: ");
 scanf("%d", &min);
 printf("Seconds for the runner: ");
 scanf("%lf", &sec);

 totsec=60*min+sec;
 ftps= FT_IN_MILE/totsec;
 mps= (double)FT_IN_MILE/FT_IN_KM*1000/totsec;

 printf("That is %.1lf feet per second, and %.2lf meters per second.\n",
        ftps,mps);
 return(0);
}//end of main

 void
 instruction(void)
{
 printf("This program will ask for the minutes and seconds for the time"
        " it\ntook for a runner to run a mile.  The program will then" 
        " calculate\nthe feet per second and meters per second for that" 
        " runner.\n");
}//displays instrctions to the user
