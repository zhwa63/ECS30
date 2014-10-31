//Author:Angela(Haowen) Zhou

#include<stdio.h>
#include<stdlib.h>
#include "vector.h"
#include "student.h"
#include "course.h"


void initialize_course(course **courses, int *course_size)
{
  *courses = (course*)malloc(100 * sizeof(course));   
  *course_size = 100;
 }//initalize course

void initialize_student(student **students, int *student_size)
{
  *students = (student*)malloc(10 * sizeof(student));
  *student_size = 10;
}//initalize student

void resize_course(course **courses,int *course_size)
{
  course *course2;
  int course_size2 = *course_size * 2,i;  

  course2 = (course*)malloc(course_size2 * sizeof(course));

  for(i = 0; i < *course_size; i++)
   course2[i] = (*courses)[i];
  
  free(*courses);

  *courses = course2;
  
  *course_size = course_size2;
  
}//resize course

void resize_student(student **students, int *student_size)
{
  student *student2;
  int student_size2 = *student_size * 2, i;
  
  student2 = (student*)malloc(student_size2 * sizeof(student));

   for(i = 0; i< *student_size; i++)
    student2[i] = (*students)[i];

  free(*students);

  *students = student2;

  *student_size = student_size2;
}//resize student

void deallocate(course *courses, student *students)
{
  free(courses);
  free(students);
}//resize
  