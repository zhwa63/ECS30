//Author: Angela(Haowen) Zhou

#include <stdio.h>
#define CANDIDATE 4+1
#define PRECINCT 5+1


void read_file(char *argv[], int table[][CANDIDATE],int row, int coloum);
//void sort(int sort_array[][]);
void show_table(int table[][CANDIDATE], int row, int coloum);
void declare_winner(int total, int table[][CANDIDATE], char name[]);

int main(int arge, char *argv[])
{
 int table[PRECINCT][CANDIDATE];
 int total;
 char name[];

 total = read_file(argv,table,PRECINCT,CANDIDATE);

 show_table(table,PRECINCT,CANDIDATE);
 
 declare_winner(total, table, name);

 return(0);
}//end of main

int read_file(char *argv[], int table[][CANDIDATE], int row, int coloum)
{
 FILE *input = fopen(argv[1], "r");

 int i, j,total1 = 0,total2 = 0,total3 = 0,total4 = 0, total;

 for(i = 0; i < row -1; i++)
 {
  for(j = 0; j < coloum; j++)
  {
    fscanf(input,"%d",&table[i][j]);
  }//for
 }//for
 fclose(input);
 
//table[5][1] = 0;
 for(i = 0; i < row; i++)
 {
    total1 += table[i][1];
    total2 += table[i][2];
    total3 += table[i][3];
    total4 += table[i][4];    
   }//for
 table[5][1] = total1;
 table[5][2] = total2;
 table[5][3] = total3;
 table[5][4] = total4;
 total = total1 + total2 + total3 + total4;

 return total;
}//read file


//void sort(int sort_array[][])
//{
//}

void show_table(int table[][CANDIDATE],int row, int coloum)
{
 //int i,j;
 char name[5] = {'A','B','C','D'};
  
 printf("	 Candidate Candidate Candidate Candidate\n");
 printf("Precinct %c	%c	%c	%c\n", name[0], name[1], 
        name[2], name[3]);
// for(i = 0; i < 6; i++)
 //{
 // for(j = 0; j < 5; j++)
 // {
  printf("%d %d %d %d %d\n",table[0][0],table[0][1],table[0][2],table[0][3],
        table[0][4]);
  printf("%d %d %d %d %d\n",table[1][0],table[1][1],table[1][2],table[1][3],
        table[1][4]);
  printf("%d %d %d %d %d\n",table[2][0],table[2][1],table[2][2],table[2][3],
        table[2][4]);
  printf("%d %d %d %d %d\n",table[3][0],table[3][1],table[3][2],table[3][3],
        table[3][4]);
  printf("%d %d %d %d %d\n",table[4][0],table[4][1],table[4][2],table[4][3],
        table[4][4]);
  printf("Total: %d %d %d %d\n",table[5][1],table[5][2],table[5][3],
        table[5][4]);
   
}//print table

void declare_winner(int total, int table[][], char name[])
{
 char winner, winner2;

   if(table[5][1]/total > 0.5)
   {
    winner = name[0];
    printf("Candidate %c is the winner.", winner);
   }//if
   else
   {
    winner = name[0];
    winner2 = name[1];
    printf("Candidates %c and %c will have a runoff.",winner, winner2);
   }//else
}//declare winner

