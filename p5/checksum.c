//Author: Angela(Haowen) Zhou

#include <stdio.h>

int main()
{
 char message; 
 int checksum,sum = 0, status;

 while(status != 1)

 {
   printf("Line: ");
  
   while(message != '.')
   {
   scanf(" %c", &message);
   sum = sum + message;
   
   }//while

   checksum = sum % 64 + 32; 
 
   if(checksum == 'N')
   {
    status = 1;
   }//if
   else
   {
    printf("Checksum: %c\n", checksum);
   }//else
   message = 0;
   sum = 0;
 }//while
 
 return(0);
}//end of main
