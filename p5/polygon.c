//Author: Angela(Haowen) Zhou

#include <stdio.h>
#include <math.h>

#define MAXIMUM_SIZE 20

int get_corners(FILE *input,double x[], double y[],int maximum_size);
void output_corners(FILE *output, double x[], double y[], int actual_size);
double polygon_area(double x[],double y[], int actual_size);

int main(int argc, char *argv[])
{
 double x[MAXIMUM_SIZE], y[MAXIMUM_SIZE],area;
 int size;

 FILE *input = fopen(argv[1], "r");
 FILE *output = fopen(argv[2], "w");
 
 size = get_corners(input, x, y, MAXIMUM_SIZE);

 output_corners(output, x, y, size);

 area = polygon_area(x,y,size);

 printf("The area is %.1f.\n",area);

 fclose(input);
 fclose(output);

 return(0);
}//end of main

 int get_corners(FILE *input, double x[], double y[], int maximum_size)
 {
  int size = 0;
  while(fscanf(input,"%lf %lf", &x[size], &y[size]) != EOF
         && size < maximum_size)
  {
    size++;
  }//while
    return size;
 }//get corners

 void output_corners(FILE *output, double x[], double y[], int actual_size)
 {
  int size;
  for(size = 0; size < actual_size; size++)
  fprintf(output, "%4.1lf %4.1lf\n", x[size], y[size]);
 }//output corners

 double polygon_area(double x[], double y[], int actual_size)
 {
  int i;
  double sum = 0, area;
  for(i = 0; i < actual_size - 2; i++)
  {
   sum = sum + (x[i + 1] + x[i]) * (y[i + 1] - y[i]);
  }//for
  
  area = fabs(sum)/2;

  return area;
}//polygon area
