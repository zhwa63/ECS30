//Author: Angela(Haowen) Zhou

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
 FILE *fp = fopen(argv[1], "r");
 int n;
 double numbers, first_num, smallest, largest, average,sum, standard_deviation, 
        sum_squares;
 
 sum = 0;
 sum_squares = 0;

 fscanf(fp,"%d",&n);

 fscanf(fp, "%lf", &numbers);
 first_num = numbers;
 smallest = first_num;
 largest = first_num;

 while(fscanf(fp,"%lf", &numbers)!= EOF)
 {
  sum = sum + numbers;
  sum_squares = sum_squares +  numbers * numbers;
 
  if(smallest >  numbers)
  {
    smallest = numbers;
  }//if

  if(largest < numbers)
  {
    largest = numbers;
  }//if
  
 }//while

  sum = sum + first_num;
  average = sum/n;

  sum_squares = sum_squares + first_num * first_num;
  standard_deviation = sqrt(sum_squares/n - average * average);
 
  printf("Smallest: %.2lf\n", smallest);
  printf("Largest:   %.2lf\n", largest);
  printf("Average:   %.2lf\n", average);
  printf("Standard deviation: %.3lf\n", standard_deviation);

 fclose(fp);
 
 return(0);
}//end of main
  
