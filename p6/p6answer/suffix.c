// Author: Sean Davis
#include <stdio.h>
#include <string.h>

void find_suffix(char *s1, char *s2, char *suffix);

int main()
{
  char s1[80], s2[80], suffix[80];
  printf("Word #1: ");
  scanf("%s", s1);
  printf("Word #2: ");
  scanf("%s", s2);
  find_suffix(s1, s2, suffix);
  printf("Common suffix: %s\n", suffix);
  return 0;
} // main()


void find_suffix(char *s1, char *s2, char *suffix)
{
  char *ptr1, *ptr2;

  ptr1 = &s1[strlen(s1)];
  ptr2 = &s2[strlen(s2)];

  while(*ptr1 == *ptr2 && ptr1 >= s1 && ptr2 >= s2)
  {
    --ptr1;
    --ptr2;
  }  // while matching suffix character

  strcpy(suffix, ++ptr1);
} // find_suffix()
