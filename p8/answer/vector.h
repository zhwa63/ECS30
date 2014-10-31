// Author: Sean Davis

#ifndef VECTOR_H
  #define VECTOR_H

#include "course.h"
#include "student.h"
#define INITIAL_COURSES_SIZE 100
#define INITIAL_STUDENTS_SIZE 10
#define RESIZE_FACTOR 2

void deallocate(Course *courses, Student *students, int courses_size);
void initialize_courses(Course **courses, int *size);
void resize_courses(Course **courses, int *size);
void initialize_students(Student **students, int *size);
void resize_students(Student **students, int *size);



#endif
