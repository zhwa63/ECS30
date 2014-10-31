//Author: Angela(Haowen) Zhou

#include <stdio.h>
#define ROW 6
#define COLOUM 5


int read_file(char *argv[], int table[][COLOUM],int row);
void sort(int sort_array[][COLOUM],int row);
void show_table(int table[][COLOUM],int row);
void declare_winner(int total, int table[][COLOUM],int row);

int main(int arge, char *argv[])
{
 int table[ROW][COLOUM];
 int total;

 total = read_file(argv, table, ROW);
 show_table(table, ROW);
 
 return (0);
}//end of main

int read_file(char *argv[], int table[][COLOUM],int row)
{
 FILE *input = fopen(argv[1], "r");

 int i,j,total1, total2, total3, total4, total;

 for(i = 0; i < row; i++)
 {
  for(j = 0; j < COLOUM; j++)
  { 
   fscanf(input, "%d", &table[i][j]);
   
  }  
 }
fclose(input);

for(j = 1; j < COLOUM; j++)
{
 for(i = 0; i < row - 1; i++)
 {
   table[5][j] = 0;
   table[5][j] = table[i][j];
 }
}
return total;

}//read file


void sort(int sort_array[][COLOUM],int row)
{
}//sort


void show_table(int table[][COLOUM],int row)
{
  int i,j;

  printf("Candidate\n"); 

  for(i = 0; i < row; i++)
 {
   for(j = 0; j < COLOUM; j++)
   {
    printf("%d	",table[i][j]);
   }
   printf("\n");
 }


}//show table

void declare_winner(int total, int table[][COLOUM],int row)
{
}//declare winner

