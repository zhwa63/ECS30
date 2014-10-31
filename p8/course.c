//Author:Angela(Haowen) Zhou

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include "course.h"
#include "vector.h"
#include "student.h"

void read_courses(course **courses, int *size, int *count, char *filename)
{
  FILE *input = fopen(filename, "r");
  char line[SIZE];

 
   if(input == NULL)
  {
    printf("(null) not readable.\n");
    exit(1);
  }//if 
 
  initialize_course(courses, size); 
  *count = 0;

  while(fgets(line,256,input))
  {
   if(isdigit((line[0])) && isdigit(line[4]))
   {
    if(*count == *size)
    {
      resize_course(courses, size);
    }//if
    (*courses)[*count].crn = atoi(strtok(line,"\t"));
    strcpy((*courses)[*count].subject,strtok(NULL,"\t"));
     if((*courses)[*count].subject[0] == '^')
     {
       strcpy((*courses)[*count].subject,strtok(NULL,"\t"));
     }//if
    strcpy((*courses)[*count].course,strtok(NULL,"\t"));

     (*count)++;
   }//if

  }//while
  fclose(input);
}//read_courses

void find_CRN(course *courses, student *students,int course_count, int student_count)
{
  int inp_crn;
  printf("Please enter a CRN: ");
  scanf("%d", &inp_crn);
  int i = 0, j = 0, count;
  
  for(;i < course_count; i++)
  {
    if(courses[i].crn == inp_crn)
    {
     printf("%s %s\n", courses[i].subject, courses[i].course);
     for(j=0; j < student_count; j++)
     {
       for(count=0; count < students[j].count;count++)
	{	
         if(students[j].crns[count] == inp_crn)
         {
           printf("%s %s\n",students[j].last, students[j].first);

         }//if
       }//end for
     }//end for
           break;
    }//if
  }//for
  if(i== course_count)
  {
     printf("CRN %d not found.\n", inp_crn);
  }//if
}//find CRN

void find_subject(course *courses, int count)
{
  int found_subject=0;
  char *inp_subject;
  int i = 0;

  inp_subject=(char*)malloc(80*sizeof(char));
  printf("Please enter a subject: ");
  do
  {
    scanf("%s", inp_subject);
  }while(strlen(inp_subject)==0);

  for(;i < count; i++)
  {
    if(strcmp(courses[i].subject, inp_subject) == 0)
    {
      printf("%d %s %s\n", courses[i].crn, courses[i].subject, courses[i].course);
      found_subject=1;
    }//if
  }//for

  if(found_subject == 0)
  {
    printf("No courses were found for %s.\n", inp_subject);
  }//if

}//find subject

void add_course(course *courses, student *students, int course_count, int student_count)
{
  char inp_sid[80]; 
  int inp_crn, i, student_index; 

  printf("Add Course\n");
  printf("Please enter the SID of the student: ");
  scanf("%s", inp_sid);

  for( i = 0; i<student_count; i++)
  {
     if(strcmp(inp_sid, students[i].sid) == 0)
     {
	student_index = i;
	break;
     }//if
  }//for

  if(i == student_count)
  {		
    printf("SID connot be found.\n");
    return;
  }//if
  if(students[student_index].count == 5)
  {
    printf("You are already taking 5 courses.\n");
    return;
  }//if
  
  printf("Please enter the CRN: ");
  scanf("%d", &inp_crn);

  for( i =0; i<students[student_index].count; i++)
  {
    if(inp_crn == students[student_index].crns[i])
    {
      printf("You are already taking this course.\n");
      return;
    }//if
  }//for
  for(i = 0 ;i < course_count; i++)
  {
    if(courses[i].crn == inp_crn)
    {
      students[student_index].crns[students[student_index].count] = inp_crn;
      ++students[student_index].count;
      return;
    }//end if
  }//end for 
  printf("There is no course with CRN #%d\n", inp_crn);
}//add course

void remove_course(course *courses, student *students, int course_count, int student_count)
{
  char inp_sid[80];
  int inp_crn, student_index, i , j; 

  printf("Remove Course\n");
  printf("Please enter the SID of the student: ");
  scanf("%s", inp_sid);
  
  for( i = 0; i<student_count; i++)
  {
     if(strcmp(inp_sid, students[i].sid) == 0)
     {
	student_index = i;
	printf("Current courses: ");
	for(j = 0; j < students[i].count; j++)
	{
	  printf("%d ",students[i].crns[j]);
	}//for
	printf("\n");
	break;
     }//if
  }//for
  if(i == student_count)
  {
    printf("SID connot be found.\n");
    return;
  }//if
  printf("Please enter the CRN: ");
  scanf("%d", &inp_crn);

  for( i =0; i< students[student_index].count; i++)
  {
    if(inp_crn == students[student_index].crns[i])
    {
      students[student_index].crns[i] = students[student_index].crns[--students[student_index].count];
      return;
    }//if
  }//for

  printf("You are not taking this course.\n");
}//remove course
  