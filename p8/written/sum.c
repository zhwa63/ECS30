#include<stdio.h>
#include<string.h>

int sum(char *arr, int index);

int main()
{
 char arr[80]; 


 printf("Enter a string.");
 scanf("%s",arr); 


 printf("%d",sum(arr,2)); 

 return 0;
}

int sum(char *arr, int index)
{
         
  if (index == 0)
  {   
      return arr[0];
   } 

  else
       return arr[index]+sum(arr,index-1);
           
 }



