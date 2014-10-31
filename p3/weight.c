//Author: Angela(Haowen) Zhou

#include <stdio.h>

int main(void)
{
  int wt_lb, ht_in;
  double bmi;

  printf("Please enter your weight in whole pounds: ");
  scanf("%d", &wt_lb);
  printf("Please enter your height in whole inches: ");
  scanf("%d", &ht_in);

  bmi=(double)(703*wt_lb)/(ht_in*ht_in);
 
  if(bmi<18.5)
  {
   printf("You have a BMI of %.1lf, and your weight status is underweight.\n",
   bmi);
  }//if BMI less than 18.5

  else if(18.5 <= bmi && bmi <= 24.9)
  {
   printf("You have a BMI of %.1lf, and your weight status is normal.\n", bmi);
  }//else if BMI between 18.5 and 24.9

  else if(25.0 <= bmi && bmi <= 29.9)
  {
   printf("You have a BMI of %.1lf, and your weight status is overweight.\n",
   bmi);
  }//else if BMI between 25 and 29.9

  else
  {
   printf("You have a BMI of %.1lf, and your weight status is obese.\n", bmi);
  }//else. when BMI greater than 29.9

  return(0); 
}//end of main
