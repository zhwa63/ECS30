// Author: Sean Davis
#include "vector.h"
#include <stdlib.h>
#include "course.h"

void initialize_courses(Course **courses, int *size)
{
  *courses = (Course*) malloc(INITIAL_COURSES_SIZE * sizeof(Course));
  *size = INITIAL_COURSES_SIZE;
}  // initalize()


void resize_courses(Course **courses, int *size)
{
  int i, size2 = *size * RESIZE_FACTOR;
  Course *courses2;

  courses2 = (Course*) malloc(size2 * sizeof(Course));

  for(i = 0; i < *size; i++)
    courses2[i] = (*courses)[i];

  free(*courses);
  *courses = courses2;
  *size = size2;
} // resize()

void deallocate(Course *courses, Student *students, int students_count)
{
  int i;

  for(i = 0; i < students_count; i++)
  {
    free (students[i].first_name);
    free(students[i].last_name);
  } // for i

  free(courses);
  free(students);
} // resize()

void initialize_students(Student **students, int *size)
{
  *students = (Student*) malloc(INITIAL_STUDENTS_SIZE * sizeof(Student));
  *size = INITIAL_STUDENTS_SIZE;
} // initialize_students()

void resize_students(Student **students, int *size)
{
  Student *temp;
  int i, size2 = *size * RESIZE_FACTOR;

  temp = (Student *) malloc(size2 * sizeof(Student));

  for(i = 0; i < *size; i++)
    temp[i] = (*students)[i];

  free(*students);
  *students = temp;
  *size = size2;
} // resize_students()



