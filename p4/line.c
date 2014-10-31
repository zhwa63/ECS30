//Author: Angela(Haowen) Zhou

#include <stdio.h>
#include <math.h>

int get_problem();
void get2_pt(int *first_x, int *first_y, int *second_x, int *second_y);
void get_pt_slope(double *slope, int *x, int *y);
void slope_intcpt_prom2_pt(int x_coordinate1, int y_coordinate1, 
       int x_coordinate2, int y_coordinate2, double *m, double *b);
double intcpt_from_pt_slope(int x_coordinate, int y_coordinate, double slope);
void display2_pt(double x_coordiante1, double y_coordinate1, 
                 double x_coordinate2, double y_coordinate2);
void display_pt_slope(double x, double y, double slope);
void display_slope_intcpt(double slope, double y);

int main()
{
 char loop;
 
 do
 {
  int problem_number,x, y, x1, y1, x2, y2; 
  double slope, y_intercept;

  problem_number = get_problem();
 
  if(problem_number == 1)
  {
   get2_pt(&x1, &y1, &x2, &y2);
 
   slope_intcpt_prom2_pt(x1, y1, x2, y2, &slope, &y_intercept);

   display2_pt(x1, y1, x2, y2);

   display_slope_intcpt(slope, y_intercept);
  }//if

  else
  {
   get_pt_slope(&slope, &x, &y);

   y_intercept = intcpt_from_pt_slope(x, y, slope);

   display_pt_slope(x, y, slope);
 
   display_slope_intcpt(slope, y_intercept);
  }//else

 printf("Do another conversion (Y or N)=> \n");
 scanf(" %c", &loop);
 }
 while(loop == 'y' || loop == 'Y');
 
 return 0;
}//end of main

int get_problem()
{
 int number;

 printf("Select the form that you would like to convert to slope-intercept"
        " form:\n1) Two-point form (you know two points on the line)\n"
        "2) Point-slope form (you know the line's slope and one point)\n"
        "=> \n");
 scanf("%d", &number);
 
 return number;
}//chose problem number

void  get2_pt(int *first_x, int *first_y,int  *second_x,int  *second_y)
{
 printf("Enter the x-y coordinates of the first point separated by a"
        " space=> ");
 scanf("%d %d", first_x, first_y);

 printf("Enter the x-y coordinates of the second point separated by a space=> "
        "\n");
 scanf("%d %d", second_x, second_y);

}//get 2 points

void get_pt_slope(double *slope, int *x, int *y)
{
 printf("Enter the slope=> ");
 scanf("%lf", slope);

 printf("Enter the x-y coordinates of the point separated by a space=> \n");
 scanf("%d %d", x, y);

}//get a point and the slope

void slope_intcpt_prom2_pt(int x_coordinate1, int y_coordinate1, 
       int x_coordinate2, int y_coordinate2, double *m, double *b)
{

  *m = (double)(y_coordinate2 - y_coordinate1) / (double)(x_coordinate2 - 
                x_coordinate1);
  *b = y_coordinate1 - (*m * x_coordinate1);
 
}//return the slope and y-intercept

double intcpt_from_pt_slope(int x_coordinate, int y_coordinate, double slope)
{
 double y_intercept;
 y_intercept = (double)y_coordinate - (slope * (double)x_coordinate);

 return y_intercept;
}//return the y-intercept from point slope form

void display2_pt(double x_coordinate1, double y_coordinate1, 
                 double  x_coordinate2, double y_coordinate2)
{
  printf("Two-point form\n");
  printf("      (%.2lf - %.2lf)\n",y_coordinate2, y_coordinate1);
  printf("  m = --------------\n");
  printf("      (%.2lf - %.2lf)\n\n", x_coordinate2, x_coordinate1);
  
}//display the two-point form

void display_pt_slope(double x, double y, double slope)
{
  printf("Point-slope form\n");
  printf("  y - %.2lf = %.2lf(x - %.2lf)\n\n", y, slope, x);

}//display the point-slope form

void display_slope_intcpt(double slope, double y_intercept)
{
 double absolute= fabs(y_intercept);
 
 printf("Slope-intercept form\n");
 
 if(y_intercept < 0)
  printf("  y = %.2lfx - %.2lf\n\n", slope, absolute);//if
 else
  printf("  y = %.2lfx + %.2lf\n\n", slope, absolute);//else
 
}//display the slope-intercept form



