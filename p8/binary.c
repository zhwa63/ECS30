//Author:Angela(Haowen) Zhou

#include<stdio.h>
#include<string.h>

void display(char binary[80]);

int main()
{
 char binary[80];
 
 printf("Binary number:");
 scanf("%s",binary);
 
 display(&binary[0]);
 
 return 0;
}//end of main

void display(char *binary)
{
 char *ptr;
 ptr = strchr(binary,'x');

 if (ptr == NULL)
    puts(binary);

 else 
 {
  *ptr = '0';
   display(&binary[0]);
  *ptr = '1';
  display(&binary[0]);
  *ptr = 'x';//back tracking
 }//else
}//display
