//Author: Angela(Haowen) Zhou

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include "course.h"
#include "vector.h"

void read_courses(int argc, char* argv[], int **crn, char ***subject, 
                  char ***courses, int *size, int *count)
{
  FILE *input = fopen(argv[1], "r");
  char line[256];

 
   if(input == NULL)
  {
    printf(" Error.");
    exit(1);
  }//if 
 
  initialize(crn, subject, courses, size); 
  *count = 0;

  while(fgets(line,256,input))
  {
   if(isdigit((line[0])) && isdigit(line[4]))
   {
    if(*count == *size)
    {
      resize(crn, courses, subject, size);
    }//if
    (*crn)[*count] = atoi(strtok(line,"\t^"));;
    strcpy((*subject)[*count], strtok(NULL,"\t"));
     if((*subject)[*count][0] == '^')
     {
       strcpy((*subject)[*count],strtok(NULL,"\t"));
     }//if
    strcpy((*courses)[*count],strtok(NULL,"\t"));
    // printf("%d %s %s\n", (*crn)[*count], (*subject)[*count], (*courses)[*count]);
     (*count)++;
   }//if

  }//while
  fclose(input);
}//read_courses

void find_CRN(int *crn, char **subject, char **courses, int count)
{
  int inp_crn;
  printf("Please enter a CRN:");
  scanf("%d", &inp_crn);
  int i = 0;
  
  for(;i < count; i++)
  {
    if(crn[i] == inp_crn)
    {
     printf("%s, %s\n", subject[i], courses[i]);
      break;
     }//end if
  }
  if(i>= count)
  {
     printf("CRN %d not found.\n", inp_crn);
  }
}

void find_subject(int *crn, char **subject, char**courses, int count)
{
  int found_subject=0;
  char *inp_subject;
  int i = 0;

  inp_subject=(char*)malloc(80*sizeof(char));
  printf("Please enter a subject:");
  do
  {
    scanf("%s", inp_subject);
  }while(strlen(inp_subject)==0);

  for(;i < count; i++)
  {
    if(strcmp(subject[i], inp_subject) == 0)
    {
      printf("%d %s %s\n", crn[i], (subject)[i], (courses)[i]);
      found_subject=1;
    }
  }
  if(found_subject == 0)
  {
    printf("No courses were found for %s.\n", inp_subject);
  }
  /*while((strcmp((subject)[i], inp_subject) !=0 )&& i < count)
  {
    i++;
  }
  
  j = i;
  while(strcmp((subject)[i], inp_subject) == 0 && j < count)
  {
    j++;
  }

  if( i < count)
  {
    for(; i<j; i++)
    {
      printf("%d %s %s\n", crn[i], (subject)[i], (courses)[i]);
    }
  }
  else
  {
    printf("No courses were found for %s.\n", inp_subject);
  }*/
}
