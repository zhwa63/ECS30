//Author: Angela(Haowen) Zhou

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void read_names(FILE *input,char **surname, char **first, char *middle_init,
                 int number_of_names);
void sort(char **surname,char **first,char *middle_init,int number_of_names);
void write_names(FILE *input,char **surname, char **first, char *middle_init,
                 int number_of_names);
void free_memory(char **surname, char **first, char *middle_init, 
                 int number_of_names);

int main(int argc,char *argv[])
{
  FILE *input = fopen(argv[1],"r");
  FILE *output = fopen(argv[2],"w");

  char **surname,**first, *middle_init;
  int number_of_names;

  fscanf(input,"%d\n", &number_of_names);
 
  surname = (char **)malloc(number_of_names * sizeof(char*));
  first = (char **)malloc(number_of_names * sizeof(char*)); 
  middle_init = (char *)malloc(number_of_names * sizeof(char));  

  read_names(input,surname,first,middle_init,number_of_names);
  sort(surname,first,middle_init,number_of_names);
  write_names(output,surname,first,middle_init,number_of_names);
  free_memory(surname, first, middle_init, number_of_names);  
 
  fclose(input);

  return(0);
}//end of main
 
void read_names(FILE *input,char **surname, char **first, char *middle_init,
                int number_of_names)
{
  char string[80];
  int i;

  for(i = 0; i < number_of_names; i++)
 {
  surname[i] = (char*)malloc(16 * sizeof(char));
  first[i] = (char*)malloc(16 * sizeof(char)); 

  fgets(string,80,input);
 
  strncpy(surname[i], strtok(string, ", "), 15);
  surname[i][15] = '\0';
  strncpy(first[i], strtok(NULL,". "),10);
  middle_init[i] = *( strtok(NULL,". \n"));
 }//for  

}//read names

void sort(char **surname,char **first,char *middle_init, int number_of_names)
{

   int i, j;
   char temp[80], temp2[80], temp3;
   
   for(i= 1; i < number_of_names; i++)
  {
   strcpy(temp,surname[i]);
   strcpy(temp2,first[i]);
   temp3 = middle_init[i];
   
    for(j = i -1; j >=0 && (strcmp(temp,surname[j]) < 0 ||(strcmp(temp,surname[j]) == 0 && strcmp(temp2, first[j])>0 )) ;j--)
   {
     strcpy(surname[j+1],surname[j]);
     strcpy(first[j+1],first[j]);
     middle_init[j+1] = middle_init[j];
   }//for
   strcpy(surname[j + 1] , temp);
   strcpy(first[j + 1], temp2);
   middle_init[j + 1] = temp3;
  }//for
  
 

 /* for( i = 0; i< number_of_names; i++)
  {
     min = i;
     for( j = 0; j < number_of_names; j++)
   {
     if(strcmp(surname[j],surname[min]) <0)
     { 
      min = j;
     }//if
   }//for
   strcpy(temp,surname[min]);
   strcpy(surname[min],surname[i]);
   strcpy(surname[i], temp);
  }//for
*/

}//sort

void write_names(FILE* output, char **surname, char **first, char *middle, 
                 int number_of_names)
{
  int i = 0;
  
  while( i < number_of_names)
  {
   fprintf(output,"%-15s %-15s %c\n", surname[i], first[i], middle[i]);
   i++;
  }//while

  fclose(output);
}//print out the names

void free_memory(char **surname, char **first, char *middle_init, 
            int number_of_names)
{
 int i;

 for(i = 0; i< number_of_names; i++)
 {
   free(surname[i]);
   free(first[i]);
 }//for
  free(surname);
  free(first);
  free(middle_init);
   
}//free memory


