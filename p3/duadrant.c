//Author: Angela(Haowen) Zhou

#include <stdio.h>;

int main()
{
 double x_coordinate; y_coordinate;

 printf("Please enter the x and y coordinates: ");
 scanf("%lf%lf", &x_coordinate, &y_coordinate);

 if(x_coordinate > 0 && y_coordinate > 0)
 {
  printf("(%.1lf, %.1lf) is in quadrant I\n", x_coordinate, y_coordinate);
 }
 
 else if(x_coordinate < 0 && y_coordinate > 0)
 {
  printf("(%.1lf, %.1lf) is in quadrant II\n", x_coordinate, y_coordinate);
 }

 else if(x_coordinate < 0 && y_coordinate < 0)
 {
  printf("(%.1lf, %.1lf) is in quadrant III\n", x_coordinate, y_coordinate);
 }
 
 else if(x_coordinate > 0 && y_coordinate < 0)
 {
  printf("(%.1lf, %.1lf) is in quadrant IV\n"), x_coordinate, y_coordinate);
 }
 
 else if(x_coordinate == 0 && y_coordinate != 0)
 {
  printf("(%.1lf, %.1lf) is on the y axis\n", x_coordinate, y_coordinate);
 }
 
 else if(x_coordinate != 0 && y_coordinate == 0)
 {
  printf("(%.1lf, %.1lf) is on the x axis\n", x_coordinate, y_coordinate);
 }

 else
 {
  printf("(%.1lf, %.1lf) is the orgin\n", x_coordinate, y_coordinate);
 }
 
 return(0);
}
