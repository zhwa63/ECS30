//Author:Angela(Haowen) Zhou

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "vector.h"

void read_student_info(const char *filename, student **students, int *student_size, int *student_count)
{
  int i = 0;
  char line[SIZE], *ptr;
  FILE *input = fopen(filename, "r");

  if(input == NULL)
 {
   printf("ERROR. not readable.\n");
   exit(1);
 }//if

  *student_count = 0;
  initialize_student(students,student_size);
  

  while(fgets(line,SIZE,input))
  {
    if(*student_count == *student_size)
      resize_student(students,student_size);
   
    ptr = strtok(line, ",");
    (*students)[*student_count].last = (char*)malloc(strlen(ptr)+1);
    strcpy((*students)[*student_count].last,ptr);

    ptr = strtok(NULL,",");
    (*students)[*student_count].first = (char*)malloc(strlen(ptr)+1);
     strcpy((*students)[*student_count].first,ptr);

    ptr = strtok(NULL,",");
    strcpy((*students)[*student_count].sid,ptr); 
    (*students)[*student_count].count=0;

    i=0;
    ptr = strtok(NULL,",\n");
    while(ptr != NULL)
    {
      (*students)[*student_count].crns[i]=atoi(ptr);
      i++;
      ptr = strtok(NULL,",\n");
    }//while
    (*students)[*student_count].count = i;
    (*student_count)++;
 }//while
  
}//read student information
   
    