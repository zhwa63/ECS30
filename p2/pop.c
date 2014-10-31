//Author: Angela(Haowen) Zhou

#include <stdio.h>
#define P_in_90 52.966
#define RATE 2.184
#define YEAR 1990

double population();

int main()
{
 int year;
 double pop;
 FILE *file;
 file = fopen("pop.txt","w");

 printf("Enter a year after 1990> ");
 scanf("%d", &year);
 
 pop = population(year);
 fprintf(file, "Predicted Gotham City population for %d (in thousands): %.3lf" 
               "\n", year, pop);
 fclose(file);
 return 0;
}//end of main

double population(int yr)
{
 double pop;
 pop = P_in_90+RATE*(yr-YEAR);
 return pop;
}//calculate the population
 
