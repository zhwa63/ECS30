//Author: Angela(Haowen) Zhou
#include<stdio.h>
#define ROW_TOTAL 8
#define COL_TOTAL 8


int find_path(char maze[ROW_TOTAL][COL_TOTAL],int row, int col);

int main(int argc, char *argv[])
{
  FILE *input = fopen(argv[1],"r");
  
 // char **maze;
  char maze[ROW_TOTAL][COL_TOTAL];
  int row,col;
 
/*  maze = (char**)malloc(ROW_TOTAL*sizeof(char*);
  for(col = 0; col < COL_TOTAL; col++)
  {
   maze[col] = (char*)malloc(COL_TOTAL*sizeof(char);
  }
*/
    for(row = 0; row < ROW_TOTAL ; row++)
   {
    for(col = 0; col < COL_TOTAL ; col++)
    {
      fscanf(input," %c",&maze[row][col]);
       
    }//for
     
   }//for
  if(find_path(maze,7,7)== 0)
  {
    printf("No path was found.\n");
  }//if
   
  return 0;
}//end main

int find_path(char maze[ROW_TOTAL][COL_TOTAL],int row, int col)
{
  if(row < 0 || col < 0 || row > 7 || col > 7 || maze[row][col] == 'X' )
	return 0;

  maze[row][col] = 'X';
  
  if(row == 0 && col == 1)
  {
    printf("(0, 1)\n"); 
    return 1;
  }//if   

  if(find_path(maze,row+1,col)||
  find_path(maze,row-1,col)||
  find_path(maze,row,col+1)||
  find_path(maze,row,col-1))
  {
    printf("(%d, %d)\n",row,col); 
    return 1;
  }//if
  return 0;
 }//find path
 
