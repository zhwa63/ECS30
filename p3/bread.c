//Author: Angela(Haowen) Zhou

#include <stdio.h>
void display_instructions(char white_or_sweet, char single_or_double,
                          char manually);
void calc_baking_time(char white_or_sweet, char single_or_double, 
                      char manually);

int main()
{
 char white_sweet, single_double, manually;

 printf("Are you making white or sweet bread (w or s)? ");
 scanf("%c",&white_sweet);
 printf("Is this a single or double loaf (s or d)? ");
 scanf(" %c",&single_double);
 printf("Are you going to bake manually (y or n)? ");
 scanf(" %c",&manually);

 display_instructions(white_sweet, single_double, manually);
 
 calc_baking_time(white_sweet, single_double, manually);

return (0);
}//end of main

void display_instructions(char white_or_sweet,char single_or_double,
                          char manually)
{
 int primary_kneading, primary_rising, secondary_kneading, secondary_rising,
     loaf_shaping, final_rising, baking_minutes, baking_seconds, cooling;

 if(white_or_sweet == 'w' || white_or_sweet == 'W')
 {
  primary_kneading = 15;
  primary_rising = 60;
  secondary_kneading = 18;
  secondary_rising = 20;
  loaf_shaping = 2;
  final_rising = 75;
  baking_minutes = 45;
  baking_seconds = 0;
  cooling = 30;
 }//if
 
 else if(white_or_sweet == 's' || white_or_sweet == 'S')
 {
  primary_kneading = 20;
  primary_rising = 60;
  secondary_kneading = 33;
  secondary_rising = 30;
  loaf_shaping = 2;
  final_rising = 75;
  baking_minutes = 35;
  baking_seconds = 0;
  cooling = 30;
 }//else if

 if(single_or_double == 'd' || single_or_double == 'D')
 {
    baking_minutes = baking_minutes*1.5;
    baking_seconds = 30;
 }//if

  printf("Primary kneading: %d minutes\n", primary_kneading);
  printf("Primary rising: %d minutes\n", primary_rising);
  printf("Secondary kneading: %d minutes\n", secondary_kneading);
  printf("Secondary rising: %d minutes\n", secondary_rising);
  printf("Loaf shaping: %d seconds\n", loaf_shaping);
  
  if(manually == 'y' || manually == 'Y')
  {
   printf("You should remove the dough for manual baking.\n");
  }//else
  else
  {
   printf("Final rising: %d minutes\n", final_rising);
   printf("Baking: %d minutes %d seconds\n", baking_minutes,
           baking_seconds);
   printf("Cooling: %d minutes\n", cooling);
  }//else
 
}//end of display_instruction

void calc_baking_time(char white_or_sweet, char single_or_double, 
char manually)
{
  int total_baking_minutes, total_baking_seconds,primary_kneading, 
      primary_rising, secondary_kneading, secondary_rising, loaf_shaping,
      final_rising, baking_minutes, baking_seconds, cooling;

  if(white_or_sweet == 'w' || white_or_sweet == 'W')
  {
   primary_kneading = 15;
   primary_rising = 60;
   secondary_kneading = 18;
   secondary_rising = 20;
   loaf_shaping = 2;
   final_rising = 75;
   baking_minutes = 45;
   baking_seconds = 0;
   cooling = 30;
  }//if
 
  else if(white_or_sweet == 's' || white_or_sweet =='S')
  {
   primary_kneading = 20;
   primary_rising = 60;
   secondary_kneading = 33;
   secondary_rising = 30;
   loaf_shaping = 2;
   baking_minutes = 35;
   baking_seconds = 0;
   cooling = 30;
  }//else if
  
  if(single_or_double == 'd' || single_or_double == 'D')
  {
   baking_minutes = baking_minutes * 1.5;
   baking_seconds = 30;
  }//if
  
  if(manually == 'y' || manually == 'Y')
  {
    final_rising = 0;
    baking_minutes = 0;
    baking_seconds = 0;
    cooling = 0;
  }//if
  
  total_baking_minutes = primary_kneading + primary_rising + secondary_kneading
                         + secondary_rising + final_rising + baking_minutes +
                         cooling;

  total_baking_seconds = loaf_shaping + baking_seconds;

  printf("\nFor a total baking time of %d minutes and %d seconds.\n", 
         total_baking_minutes, total_baking_seconds);
}//end of calc_baking_time

