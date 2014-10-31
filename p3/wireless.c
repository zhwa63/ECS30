//Author: Angela(Haowen) Zhou

#include <stdio.h>
#include <math.h>


#define FLAT_RATE 3999
#define OFFER_WEEKDAY_MINUTES 600
#define ADDITIONAL_WEEKDAY 40
#define TAXES 0.0525
#define CENTS_PER_DOLLAR 100

int main()
{
  int weekday_minutes, night_minutes, weekend_minutes,average_minute_cost,taxes;
  double  display_pretax_bill, display_total_bill, display_average_minute_cost,
         pretax_bill,display_taxes, total_bill;
 
  printf("Please enter the number of weekday minutes, night minutes: ");
  scanf("%d%d", &weekday_minutes, &night_minutes);
  printf("Please enter the number of weekend minutes: ");
  scanf("%d", &weekend_minutes);

  pretax_bill = FLAT_RATE + (weekday_minutes - OFFER_WEEKDAY_MINUTES)*
               ADDITIONAL_WEEKDAY;
  taxes = floor(pretax_bill*TAXES+0.5);
  total_bill = pretax_bill + taxes;

  average_minute_cost =floor( pretax_bill/(weekday_minutes + night_minutes +
                      weekend_minutes)+0.5);

  display_average_minute_cost = (double)average_minute_cost/CENTS_PER_DOLLAR;
  display_taxes = (double)taxes/CENTS_PER_DOLLAR;
  display_pretax_bill = pretax_bill/CENTS_PER_DOLLAR;
  display_total_bill = total_bill/CENTS_PER_DOLLAR;

  printf("\nWeekday minutes: %d, night minutes: %d, weekend minutes: %d\n",
         weekday_minutes, night_minutes, weekend_minutes);
  printf("Average minute cost: $%.2lf\n", display_average_minute_cost);
 
  printf("\nPretax bill: $%.2lf\n", display_pretax_bill);
  printf("Taxes:       $ %.2lf\n", display_taxes);
  printf("Total bill:  $%.2lf\n", display_total_bill);

  return(0);
}//end of main 
