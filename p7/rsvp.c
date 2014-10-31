//Author: Angela(Haowen) Zhou

#include<stdio.h>

#include "course.h"
#include "vector.h"



int get_choice()
{
  int choice;
  do
  {
    printf("\nRSVP Menu\n");
    printf("0. Done.\n1. Find by CRN.\n2. Find by subject.\n"
           "Your choice (0 - 2):");
    scanf("%d", &choice);
    if(choice < 0 || choice > 2)
    {
      printf("Your choice is outside the acceptable range. Please try again.\n");
    }
  }while(choice < 0 || choice > 2);
  
   return choice;
}

void display_info(course *courses, int count)
{
   int choice;

   do
   {
     choice = get_choice();

     switch(choice)
     {
       case 1: find_CRN(crn, subject, courses, count);
               break;
       case 2: find_subject(crn, subject, courses, count);
               break;
     }
  }while(choice != 0);
}

int main(int argc, char **argv)
{
  char **subjects, **courses;
  int *crn, count, size;

  read_courses(argc, argv, &crn, &subjects, &courses, &size, &count);

  display_info(crn, subjects, courses, count);

  return 0;
}
