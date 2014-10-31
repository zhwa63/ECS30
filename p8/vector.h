//Author:Angela(Haowen) Zhou

#ifndef VECTOR_H
 #define VECTOR_H

 #include "student.h"
 #include "course.h"

void initialize_course(course **courses, int *course_size);

void initialize_student(student **students, int *student_size);


void resize_course(course **courses, int *course_size);

void resize_student(student **students, int *student_size);


void deallocate(course *courses, student *students);

#endif