//Authur: Angela(Haowen) Zhou

#include<stdio.h>
#include "student.h"
#include "course.h"
#include "vector.h"

int get_choice();

void display_info(course *courses, student *students,int course_count,int student_count);


int main(int argc, char *argv[])
{
  course *courses;
  student *students;
  int course_count, course_size, student_count, student_size; 
 
  read_courses(&courses, &course_size, &course_count, argv[1]);

  read_student_info(argv[2], &students, &student_size, &student_count);

  display_info(courses, students,course_count,student_count);

  deallocate(courses,students);

  return 0;
}//end of main

int get_choice()
{
 int choice;
 do
 {
   printf("\nRSVP Menu\n");
   printf("0. Done.\n1. Find by CRN.\n2. Find by subject.\n3. Add course."
         "\n4. Remove course.\nYour choice (0 - 4): ");
   scanf("%d", &choice);

   if(choice < 0 || choice > 4)
   {
     printf("Your choice is outside the acceptable range.  Please try again.\n");
   }//if
 }while(choice < 0 || choice > 4);

  return choice;
}//get choice

void display_info(course *courses, student *students, int course_count, int student_count)
{
   int choice;

   do
  {
    choice = get_choice();

     switch(choice)
     {
        case 1: find_CRN(courses,students,course_count,student_count);
                break;

        case 2: find_subject(courses,course_count);
                break;
          
        case 3: add_course(courses, students,course_count,student_count);
                break;
    
        case 4: remove_course(courses, students,course_count,student_count);
                break;
      }//switch
  }while(choice != 0);
}//display info