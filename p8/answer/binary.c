// Author: Sean Davis
#include <stdio.h>

void display(char *number, int pos);

int main()
{
  char number[80];
  printf("Binary number: ");
  scanf("%s", number);
  display(number, 0);
  return 0;
}  // main()

void display(char *number, int pos)
{
  if(number[pos] == '\0')
    puts(number);
  else
    if(number[pos] != 'x')
      display(number, pos + 1);
    else
    {
      number[pos] = '0';
      display(number, pos + 1);
      number[pos] = '1';
      display(number, pos + 1);
      number[pos] = 'x';
    }
}

