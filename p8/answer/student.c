// Author: Sean Davis
#include "student.h"
#include "vector.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int find_student(const Student *students, int count)
{
  int i;
  char SID[SMALL_ARRAY_SIZE];
  printf("Please enter the SID of the student: ");
  scanf("%s", SID);

  for(i = 0; i < count; i++)
    if(strcmp(SID, students[i].SID) == 0)
      return i;

  printf("A student with SID #%s was not found.\n", SID);
  return -1;
}  // find_student()

void read_students(Student **students, int *count, int *size,
  const char *filename)
{
  char line[80], *ptr;
  FILE *fp = fopen(filename, "r");

  if(fp == NULL)
  {
    printf("%s not readable.\n", filename);
    exit(1);
  } // if file not openable
  
  *count = 0;
  initialize_students(students, size);

  while(fgets(line, 80, fp))
  {
    if(*count == *size)
      resize_students(students, size);

    ptr = strtok(line, ",");
    (*students)[*count].first_name = (char*) malloc(strlen(ptr) + 1);
    strcpy((*students)[*count].first_name, ptr);
    ptr = strtok(NULL, ",");
    (*students)[*count].last_name = (char*) malloc(strlen(ptr) + 1);
    strcpy((*students)[*count].last_name, ptr);
    strcpy((*students)[*count].SID, strtok(NULL, ",\n"));
    (*students)[*count].count = 0;

    while((ptr = strtok(NULL, ",\n")) != NULL)
      (*students)[*count].CRNs[(*students)[*count].count++] = atoi(ptr);

    (*count)++;

  } // while more in file

} // read_students()
