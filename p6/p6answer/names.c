// Author: Sean Davis
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_memory(char **surname, char **first, char *middle_init, int count);
void read_names(FILE *fp, char **surname, char **first, char *middle_init,
  int count);
void sort(char **surname, char **first, char *middle_init, int count);
void write_names(char *filename, char **surname, char **first,
  char *middle_init, int count);

int main(int argc, char *argv[])
{
  char **surname, **first, *middle_init;
  int count, i;
  FILE* fp = fopen(argv[1], "r");
  fscanf(fp, "%d", &count);
  surname = (char**) malloc(count * sizeof(char*));
  first = (char**) malloc(count * sizeof(char*));
  middle_init = (char*) malloc(count * sizeof(char));

  for(i = 0; i < count; i++)
  {
    surname[i] = (char*) malloc(16 * sizeof(char));
    first[i] = (char*) malloc(16 * sizeof(char));
  } // for i

  read_names(fp, surname, first, middle_init, count);
  sort(surname, first, middle_init, count);
  write_names(argv[2], surname, first, middle_init, count);
  free_memory(surname, first, middle_init, count);
  return 0;
} // main()


void free_memory(char **surname, char **first, char *middle_init, int count)
{
  int i;

  for(i = 0; i < count; i++)
  {
    free(surname[i]);
    free(first[i]);
  } // for i

  free(surname);
  free(first);
  free(middle_init);
}  // free_memory()


void read_names(FILE *fp, char **surname, char **first, char *middle_init,
  int count)
{
  char line[80], *ptr;
  int i;
  fgets(line, 80, fp);
  
  for(i = 0; i < count; i++)
  {
    fgets(line, 80, fp);
    ptr = strtok(line, ",");
    strncpy(surname[i], ptr, 15);
    surname[i][15] = '\0';
    strcpy(first[i], strtok(NULL, " "));
    ptr = strchr(first[i], '.');
    if(ptr)
      *ptr = '\0';

    ptr = strtok(NULL, ".");
    middle_init[i] = *ptr;
  } // for i

  fclose(fp);
}  // read_names()


void sort(char **surname, char **first, char *middle_init, int count)
{
  int i, j;
  char surname_temp[16], first_temp[16], middle_temp;

  for(i = 1; i < count ; i++)
  {
    strcpy(surname_temp, surname[i]);
    strcpy(first_temp, first[i]);
    middle_temp = middle_init[i];

    for(j = i - 1; j >= 0
      && (strcmp(surname[j], surname_temp) > 0
        || (strcmp(surname[j], surname_temp) == 0
        && strcmp(first[j], first_temp) > 0));
      j--)
    {
      strcpy(surname[j + 1], surname[j]);
      strcpy(first[j + 1], first[j]);
      middle_init[j + 1] = middle_init[j];
    }  // for j

    strcpy(surname[j +  1], surname_temp);
    strcpy(first[j + 1], first_temp);
    middle_init[j + 1] = middle_temp;
  }  // for i
}  // sort()


void write_names(char *filename, char **surname, char **first,
  char *middle_init, int count)
{
  int i;
  FILE *fp = fopen(filename, "w");

  for(i = 0; i < count; i++)
    fprintf(fp, "%-15s %-15s %c\n", surname[i], first[i], middle_init[i]);

  fclose(fp);
}  // write_names()

