//Author: Angela(Haowen) Zhou

#ifdef VECTOR_H
 #define VECTOR_H


void initialize(int **crn, char ***subject, char ***courses, int *size);
void resize(int **crn, char ***subject, char ***courses, int *size);
void deallocate(char ***courses, char ***subject, int size);

#endif
