#include<stdio.h>
#include<string.h>

void nonblank(char *arr, int index);

int main()
{
 char arr[80]; 


 printf("Enter a string.");
 scanf("%s",arr); 


 nonblank(arr,0); 

 return 0;
}

void nonblank(char *arr, int index)
{
   if(arr[index] == 0)
      {
         printf("%c",arr[index-1]);
      }
      else
        nonblank(arr,index+1);            
 }
