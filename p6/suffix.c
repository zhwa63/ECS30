//Author: Angela(Haowen) Zhou

#include<stdio.h>
#include<string.h>

void find_suffix(char word1[], char word2[],char suffix[]);

int main()
{
  char word1[80], word2[80], suffix[80];

  printf("Word #1: ");
  fgets(word1,80,stdin);

  printf("Word #2: ");
  fgets(word2,80,stdin);
  
  find_suffix(word1, word2, suffix);

  printf("Common suffix: ");
  printf("%s",suffix);

  return(0);
}//end of main

void find_suffix(char word1[],char word2[],char suffix[])
{
  int length1, length2;

  length1 = strlen(word1);
  length2 = strlen(word2);

  while(word1[length1] == word2[length2])
  {
    strcpy(suffix, &word1[length1]);
    length1--;
    length2--;
  }//while

}//find the suffix
