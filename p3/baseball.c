//Author: Angela(Haowen) Zhou

#include <stdio.h>

int main(int argc, char *argv[])
{
  FILE *fp = fopen(argv[1],"r");

  int player;
  double batting_average, hit = 0, hit_and_out = 0;
  char at_bat;
  
  while(fscanf(fp, "%d", &player)!=EOF)
  {
    fscanf(fp, "%c", &at_bat);
    printf("Player %d's record:", player);

    while(at_bat != '\n')
    {
     fscanf(fp,"%c", &at_bat);
     printf("%c", at_bat);
     if(at_bat == 'H')
     {
      hit++;
     }//if it is a hit
     if(at_bat == 'O' || at_bat == 'H')
     {
     hit_and_out++;
     }//if it is an out of hit
    }//while still on a same line

  batting_average = hit/hit_and_out;

  printf("Player %d's batting average: %.3lf\n\n", player, batting_average);
  hit = 0;
  hit_and_out = 0;
 }//while not end of the file

 fclose(fp);

 return(0);
}//end of main
