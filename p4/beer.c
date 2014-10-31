//Author: Angela(Haowen) Zhou

#include <stdio.h>
#define PIELS 1
#define COORS 2
#define BUD 3
#define IRON_CITY 4

int main(int argc, char *argv[])
{
 int piels,coors, bud, iron_city, id_number, amount_purchased;

 FILE *fp = fopen(argv[1], "r");

 fscanf(fp, "%d%d%d%d", &piels, &coors, &bud, &iron_city);

 while(fscanf(fp,"%d",&id_number) != EOF)
 {
  fscanf(fp,"%d", &amount_purchased);
 
  if(id_number == PIELS)
  {
   piels = piels + amount_purchased;
  }//if

  else if(id_number == COORS)
  {
   coors = coors + amount_purchased;
  }//else if
 
  else if(id_number == BUD)
  {
   bud = bud + amount_purchased;
  }//else if

  else
  {
   iron_city = iron_city + amount_purchased;
  }//else
 }//while
  
 printf("Piels:        %d\n", piels);
 printf("Coors:       %d\n", coors);
 printf("Bud:        %d\n", bud);
 printf("Iron City:    %d\n", iron_city);

 return(0);
}//end of main
  
  
