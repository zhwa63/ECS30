// Author: Sean Davis
#include <stdio.h>
#include <string.h>
#include "course.h"
#include "vector.h"
#include "student.h"
#define NUM_CHOICES 4
#define COURSE_FILE_ARG 1
#define STUDENT_FILE_ARG 2

void display_info(Course *courses, Student *students, int courses_count,
  int students_count);
int get_choice(void);

int main(int argc, char **argv)
{
  Course *courses;
  Student *students;
  int courses_count, students_count, students_size;

  read_courses(&courses, &courses_count, argv[COURSE_FILE_ARG]);
  read_students(&students, &students_count, &students_size,
    argv[STUDENT_FILE_ARG]);
  display_info(courses, students, courses_count, students_count);
  deallocate(courses, students, students_count);
  return 0;
}  // main()

int get_choice(void)
{
  int choice;

  do
  {
    printf("\nRSVP Menu\n");
    printf("0. Done.\n");
    printf("1. Find by CRN.\n");
    printf("2. Find by subject.\n");
    printf("3. Add course.\n");
    printf("4. Remove course.\n");
    printf("Your choice (0 - 4): ");
    scanf("%d", & choice);

    if(choice < 0 || choice > NUM_CHOICES)
      printf("Your choice is outside the acceptable range.  Please try again.\n");
  }  while(choice < 0 || choice > NUM_CHOICES);

  return choice;
} // get_choice


void display_info(Course *courses, Student *students, int courses_count,
  int students_count)
{
  int choice;

  do
  {
    choice = get_choice();

    switch(choice)
    {
      case 1: find_CRN(courses, students, courses_count, students_count); break;
      case 2: find_subject(courses, courses_count); break;
      case 3:
        add_course(courses, students, courses_count, students_count);
        break;
      case 4:
        remove_course(courses, students, courses_count, students_count);
        break;
    } // switch
  } while(choice != 0);

} // display_info()

