// Author: Sean Davis
#include <stdio.h>

void read_file(char *filename, int votes[6][4]);
void sort(int votes[6][4], char names[4]);
void declare_winner(int votes[6][4], char names[4]);
void show_table(int votes[6][4], char names[4]);

int main(int argc, char *argv[])
{
  int votes[6][4];
  char names[5] = "ABCD";
  read_file(argv[1], votes);
  sort(votes, names);
  show_table(votes, names);
  declare_winner(votes, names);
  return 0;
} // main()


void declare_winner(int votes[6][4], char names[4])
{
  int col, total = 0;

  for(col = 0; col < 4; col++)
    total += votes[5][col];

  if(votes[5][0] * 2 > total )
    printf("Candidate %c is the winner.\n", names[0]);
  else
    printf("Candidates %c and %c will have a runoff.\n", names[0], names[1]);
}  // declare_winner()

void show_table(int votes[6][4], char names[4])
{
  int row, col;

  printf("           Candidate  Candidate  Candidate  Candidate\n");
  printf("Precinct       ");

  for(col = 0; col < 4; col++)
    printf("%c          ", names[col]);

  printf("\n");

  for(row = 0; row < 5; row++)
  {
    printf("%4d      ", row + 1);

    for(col = 0; col < 3; col++)
      printf("%7d    ", votes[row][col]);

    printf("%7d\n", votes[row][col]);
  } // for row

  printf("Total:      ");

  for(col = 0; col < 3; col++)
    printf("%5d      ", votes[5][col]);

  printf("%5d\n\n", votes[5][col]);
}  // show_table


void sort(int votes[6][4], char names[4])
{  // using insertion sort
  int row, col, col2, temp[6];
  char temp_name;

  for(col = 1; col < 4; col++)
  {
    for(row = 0; row < 6; row++)
      temp[row] = votes[row][col];

    temp_name = names[col];

    for(col2 = col; col2 > 0 && temp[5] > votes[5][col2 -1] ; col2-- )
    {
      for(row = 0; row < 6; row++)
        votes[row][col2] = votes[row][col2 - 1];

      names[col2] = names[col2 - 1];
    }  // for col2

    for(row = 0; row < 6; row++)
      votes[row][col2] = temp[row];

    names[col2] = temp_name;
  } // for col
}  // sort()


void read_file(char *filename, int votes[6][4])
{
  int row, col, precinct;
  FILE *fp = fopen(filename, "r");
  
  for(col = 0; col < 4; col++)
    votes[5][col] = 0;
  
  for(row = 0; row < 5; row++ )
  {
    fscanf(fp, "%d", &precinct);

    for(col = 0; col < 4; col++)
    {
      fscanf(fp, "%d", &votes[row][col]);
      votes[5][col] += votes[row][col];
    } // for col
  } // for row
}  // read_file()

