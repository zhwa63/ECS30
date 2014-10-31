//Author:Angela(Haowen) Zhou

#ifndef STUDENT_H
 #define STUDENT_H

typedef struct
{
  char *first;
  char *last;
  char sid[12];
  int crns[5];
  int count;
}student;

#define SIZE 265

void read_student_info(const char *filename, student **students, int *student_size, int *student_count);

#endif
