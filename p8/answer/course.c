// Author: Sean Davis
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "course.h"
#include "vector.h"

void add_course(const Course *courses, Student *students, int courses_count,
  int students_count)
{
  int i, index, CRN;

  printf("Add Course\n");
  index = find_student(students, students_count);

  if(index == NOT_FOUND)
    return;

  if(students[index].count == MAX_COURSES)
  {
    printf("You are already taking %d courses.\n", MAX_COURSES);
    return;
  } // if student has full load

  printf("Please enter the CRN: ");
  scanf("%d", &CRN);

  for(i = 0; i < courses_count; i++)
    if(courses[i].CRN == CRN)
      break;

  if(i == courses_count)
  {
    printf("There is no course with CRN #%d\n", CRN);
    return;
  } // if CRN not found

  for(i = 0; i < students[index].count; i++)
    if(students[index].CRNs[i] == CRN)
    {
      printf("You are already taking that course.\n");
      return;
    } // if already enrolled the course

  students[index].CRNs[i] = CRN;
  students[index].count++;
} // add_course()

void remove_course(const Course *courses, Student *students, int courses_count,
  int students_count)
{
  int index, i, CRN;

  printf("Remove Course\n");
  index = find_student(students, students_count);

  if(index == NOT_FOUND)
    return;


  printf("Current courses: ");

  for(i = 0; i < students[index].count; i++)
    printf("%d ", students[index].CRNs[i]);

  printf("\nPlease enter the CRN: ");
  scanf("%d", &CRN);

  for(i = 0; i < students[index].count; i++)
    if(students[index].CRNs[i] == CRN)
    {
      students[index].CRNs[i] = students[index].CRNs[--students[index].count];
      return;
    } // if found the CRN

  printf("You are not taking that course.\n");
} // remove_course()

void find_CRN(const Course *courses, const Student *students, int courses_count,
  int students_count)
{
  int i, j, k, CRN;
  printf("Please enter a CRN: ");
  scanf("%d", &CRN);

  for(i = 0; i < courses_count; i++)
    if(courses[i].CRN == CRN)
    {
      printf("%s %s\n", courses[i].subject, courses[i].course);
      for(j = 0; j < students_count; j++)
        for(k = 0; k < students[j].count; k++)
          if(students[j].CRNs[k] == CRN)
            printf("%s %s\n", students[j].first_name, students[j].last_name);

      break;
    } // if CRN matches

  if(i == courses_count)
    printf("CRN %d not found.\n", CRN);

} // find_CRN()

void find_subject(const Course *courses, int count)
{
  char subject[SMALL_ARRAY_SIZE];
  int i, found = 0;

  printf("Please enter a subject: ");
  do
  {
    scanf("%s", subject);
  } while(strlen(subject) == 0);

  for(i = 0; i < count; i++)
  {
    if(strcmp(subject, courses[i].subject) == 0)
    {
      printf("%d %s %s\n", courses[i].CRN, courses[i].subject,
        courses[i].course);
      found = 1;
    }
  } // for i

  if(!found)
    printf("No courses were found for %s.\n", subject);

} // find_subjects()


void read_courses(Course **courses, int *count, const char *filename)
{
  char line[LARGE_ARRAY_SIZE];
  FILE *fp = fopen(filename, "r");
  int size;

  if(fp == NULL)
  {
    printf("%s not readable.\n", filename);
    exit(1);
  } // if file not openable

  initialize_courses(courses, &size);
  *count = 0;

  while(fgets(line, LARGE_ARRAY_SIZE, fp))
  {
    if(isdigit(line[0]) && isdigit(line[CRN_END]))
    {
      if(*count == size)
        resize_courses(courses, &size);

      (*courses)[*count].CRN = atoi(strtok(line, "\t"));
      strcpy((*courses)[*count].subject, strtok(NULL, "\t"));

      if((*courses)[*count].subject[0] == '^')
        strcpy((*courses)[*count].subject, strtok(NULL, "\t"));

      strcpy((*courses)[*count].course, strtok(NULL, "\t"));  

      (*count)++;
    }  // if starts with a CRN
  } // while more in file
} // parse()


