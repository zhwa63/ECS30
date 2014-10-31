// Author: Sean Davis
#include <stdio.h>
#include <math.h>

#define MAX_SIZE 20
int get_corners(FILE *fp, double x[], double y[], int max_size);
void output_corners(FILE *fp, double x[], double y[], int size );
double polygon_area(double x[], double y[], int size);

int main(int argc, char *argv[])
{
  int size;
  double x[MAX_SIZE], y[MAX_SIZE], area;
  FILE *fp = fopen(argv[1], "r");

  size = get_corners(fp, x, y, MAX_SIZE);
  fclose(fp);
  fp = fopen(argv[2], "w");
  output_corners(fp, x,y, size );
  area = polygon_area(x, y, size);
  printf("The area is %.1lf.\n", area);
  return 0;
} // main()

int get_corners(FILE *fp, double x[], double y[], int max_size)
{
  int i;

  for(i = 0; i < max_size && fscanf(fp, "%lf%lf", &x[i], &y[i]) != EOF; i++);

  return i;
} // get_corners()

void output_corners(FILE *fp, double x[], double y[], int size )
{
  int i;

  for(i = 0; i < size; i++)
    fprintf(fp, "%4.1lf %4.1lf\n", x[i], y[i]);
}  // output_corners()

double polygon_area(double x[], double y[], int size)
{
  int i;
  double area = 0;

  for(i = 0; i < size - 2; i++)
    area += (x[i + 1] + x[i]) * (y[i + 1] - y[i]);

  return fabs(area / 2);
}  // polygon_area()

