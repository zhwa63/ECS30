// Author: Sean Davis
#include <stdio.h>

int main()
{
  int len, total;
  char c;

  do
  {
    len = 0;
    total = 0;
    printf("Line: ");
    
    do
    {
      scanf("%c", &c);
      total += c;
      len++;
    } while(c != '.');

    do
    {
      scanf("%c", &c);
    }  while(c != '\n');

    if(len > 1)
      printf("Checksum: %c\n", total % 64 + ' ');
  }  while(len != 1);

  return 0;
} // main()

