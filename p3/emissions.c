//Author: Angela(Haowen) Zhou

#include <stdio.h>

int main()
{
 int pollutant_number;
 double grams_per_mile, odometer, first_50000_miles, second_50000_miles;

 printf("(1) Carbon monoxide\n(2) Hydrocarbons\n");
 printf("(3) Nitrogen oxides\n(4) Nonmethane hydrocarbons\n");
 printf("Enter pollutant number>> ");
 scanf("%d", &pollutant_number);
 printf("Enter number of grams emitted per mile>> ");
 scanf("%lf", &grams_per_mile);
 printf("Enter odometer reading>> ");
 scanf("%lf", &odometer);

 switch(pollutant_number)
 {
  case 1:
  first_50000_miles = 3.4;
  second_50000_miles = 4.2;
  break;

  case 2:
  first_50000_miles = 0.31;
  second_50000_miles = 0.39;
  break;
 
  case 3:
  first_50000_miles = 0.4;
  second_50000_miles = 0.5;
  break;
 
  case 4:
  first_50000_miles = 0.25;
  second_50000_miles = 0.31;
  break;

  default:
  printf("Please enter number between 1 to 4.");
  break;
 }//switch
  
  if(grams_per_mile < first_50000_miles)
  {
    printf("Emissions do not exceed permitted level of %.2lf grams/mile.\n", first_50000_miles);
  }//if

  else if(grams_per_mile >= first_50000_miles && grams_per_mile < second_50000_miles)
  {
    if(odometer <= 50000)
    {
      printf("Emissions exceed permitted level of %.2lf grams/mile.\n", first_50000_miles);
    }//if
    else
    {
     printf("Emissions do not exceed permitted level of %.2lf grams/mile.\n", second_50000_miles);
    }//else
  }//if
  else 
  {
   printf("Emissions exceed permitted level of %.2lf grams/mile.\n", second_50000_miles);
  }//else
  
  return(0);
}//end of main
