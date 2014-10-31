//Author: Angela(Haowen) Zhou

#ifndef COURSE_H
  #define COURSE_H

void read_courses(int argc, char* argv[], int **crn, char ***subject, 
                  char ***courses, int *size, int *count);
void find_CRN(int *crn, char **subject, char **courses, int count);
void find_subject(int *crn, char **subject, char **courses, int count);

#endif
