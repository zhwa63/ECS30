//Author: Angela(Haowen) Zhou

#include<stdio.h>
#include<string.h>

int main()
{
 char string[80], temp[80], reverse[80]="", *ptr;


 printf("Input: ");
 fgets(string,80,stdin);

 ptr = strtok(string," \n");
 //sprintf(reverse,"%s",ptr);


while(ptr != NULL)
 {

  sprintf(temp,"%s %s", ptr, reverse);
  strcpy(reverse,temp);

  ptr = strtok(NULL," \n");
 }//while
// length = strlen(string);
// reverse[length]='\0';

 printf("Reversed: %s\n", reverse); 
 return(0);
}//end of main
