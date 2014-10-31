// Author: Sean Davis
#ifndef STUDENT_H
#define STUDENT_H

#define MAX_COURSES 5
#define SID_SIZE 12

typedef struct
{
  char *first_name;
  char *last_name;
  char SID[SID_SIZE];
  int CRNs[MAX_COURSES];
  int count;
} Student;

void read_students(Student **students, int *count, int *size,
  const char *filename);
int find_student(const Student *students, int count);

#endif
