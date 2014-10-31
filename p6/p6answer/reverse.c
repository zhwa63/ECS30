// Author: Sean Davis

#include <stdio.h>
#include <string.h>

int main()
{
  char words[80], reversed[80] = "", temp[80], *ptr;
  printf("Input: ");
  fgets(words, 80, stdin);
  ptr = strtok(words, " \n");

  while(ptr)
  {
    sprintf(temp, "%s %s", ptr, reversed);
    strcpy(reversed, temp);
    ptr = strtok(NULL, " \n");
  } // while more words on line

  printf("Reversed: %s\n", reversed);
  return 0;
} // main()

