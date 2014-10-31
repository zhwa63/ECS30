#ifndef COURSES_H
  #define COURSES_H

#include "student.h"
#define SUBJECT_SIZE 4
#define COURSE_SIZE 6
#define DAYS_SIZE 6
#define NOT_FOUND -1
#define LARGE_ARRAY_SIZE 256
#define SMALL_ARRAY_SIZE 20
#define CRN_END 4



typedef struct
{
  int CRN;
  char subject[SUBJECT_SIZE];
  char course[COURSE_SIZE];
} Course;

void add_course(const Course *courses, Student *students, int courses_count,
  int students_count);
void find_CRN(const Course *courses, const Student *students, int courses_count,
  int students_count);

void find_subject(const Course *courses, int courses_count);
void read_courses(Course **courses, int *count, const char *filename);
void remove_course(const Course *courses, Student *students, int courses_count,
  int students_count);









#endif
