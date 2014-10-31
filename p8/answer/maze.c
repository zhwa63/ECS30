// Author: Sean Davis
#include <stdio.h>

int find_path(char maze[8][9], int row, int col);

int main(int argc, char **argv)
{
  char maze[8][9];
  int i;
  FILE *fp;

  fp = fopen(argv[1], "r");

  for(i = 0; i < 8; i++)
    fscanf(fp, "%s", maze[i]);

  if(find_path(maze, 7, 7) == 0)
    printf("No path was found.\n");

  return 0;
}  // main()


int find_path(char maze[8][9], int row, int col)
{
  if(row < 0 || row > 7 || col < 0 || col > 7)
    return 0; // off maze

  if(maze[row][col] == 'X')
    return 0;

  maze[row][col] = 'X';
  
  if(row == 0 && col == 1)
  {
    printf("(0, 1)\n");
    return 1;
  }


  if(find_path(maze, row + 1, col) || find_path(maze, row - 1, col)
    || find_path(maze, row, col - 1) || find_path(maze, row, col + 1))
  {
    printf("(%d, %d)\n", row, col);
    return 1;
  }

  return 0;
} // find_path()


