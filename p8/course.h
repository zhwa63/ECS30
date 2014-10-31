//Author:Angela(Haowen) Zhou

#ifndef COURSE_H
 #define COURSE_H

#include "student.h"

typedef struct
{
 int crn;
 char subject[4];
 char course[5];
}course;

void read_courses(course **courses, int *size, int *count, char *filename);

void find_CRN(course *courses, student *students,int course_count, int student_count);

void find_subject(course *courses, int count);

void add_course(course *courses, student *students, int course_count, int student_count);

void remove_course(course *courses, student *students, int course_count, int student_count);

#endif
