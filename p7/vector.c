//Author: Angela(Haowen) Zhou

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

#define ARRAY_SIZE 100
#define COURSE_SIZE 6
#define SUBJECT_SIZE 4

void initialize(int **crn, char ***subject, char ***courses, int *size)
{
 int i;

 *crn = (int*)malloc(ARRAY_SIZE*sizeof(int));
 *courses = (char**)malloc(ARRAY_SIZE*sizeof(char*));
 *subject = (char**)malloc(ARRAY_SIZE*sizeof(char*));
 for(i = 0; i<ARRAY_SIZE ; i++)
 {
  (*courses)[i] = (char*)malloc(COURSE_SIZE*sizeof(char));
  (*subject)[i] = (char*)malloc(SUBJECT_SIZE*sizeof(char));
 }
 *size = ARRAY_SIZE ;
}

void resize(int **crn, char ***subject, char ***courses, int *size)
{
  int *temp_crn,i;
  int new_size= *size * 2;
  char **temp_courses, **temp_subject;

 temp_crn = (int*)malloc(new_size * sizeof(int));
 temp_courses = (char**)malloc(new_size *sizeof(char*));
 temp_subject = (char**)malloc(new_size*sizeof(char*)); 

  for(i = 0; i < *size; i++)
  {
    temp_crn[i] = (*crn)[i];
    temp_courses[i] = (*courses)[i];
    temp_subject[i] = (*subject)[i];
  }

 free(*crn);
 free(*courses);
 free(*subject);

 *crn = temp_crn;
 *courses = temp_courses;
 *subject = temp_subject;


  for(; i < new_size; i++)
  {
    (*courses)[i] = (char*)malloc(COURSE_SIZE*sizeof(char));
    (*subject)[i] = (char*)malloc(SUBJECT_SIZE*sizeof(char));
  }
 *size = new_size; 
}

void deallocate(char **subject, char **courses, int size, int *crn)
{
 int i;
 for(i = 0; i< size; i++); 
 {
  free((courses)[i]);
  free((subject)[i]);
 }

 free(crn);
 free(courses);
 free(subject);
}
