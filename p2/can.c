// Author: Angela(Haowen) Zhou

#include <stdio.h>
#include <math.h>

void instruction();
double surface_area();

int
main()
{
 FILE *input;
 input = fopen("cans.txt","r");
 
 double radius, height,cost_per_sq_cm,quantity,total_cost,sur_area;
 
 instruction();

 int counter;
 for(counter=1; i<4; i++) 
 {  
 fscanf(input,"%lf%lf%lf%lf",&radius, &height, &cost_per_sq_cm, &quantity);

 sur_area=surface_area(radius, height); 

 total_cost= sur_area*cost_per_sq_cm*quantity;

 printf("Each can #%d has surface area %8.3lf, and the run will cost $%.2lf.\n",
         i,sur_area, total_cost);
 }//for loop
}//end of main
void instruction(void)
{
 printf("This program calculates the cost of materials for three open-top"
        " cylindrical\ncontainers.  It reads the radius, height, cost per"
        " square centimeter, and \nquantity for each container from the file"
        " cans.txt.  Each line in cans.txt has \nthe format: radius height" 
        " cost_per_sq_cm quantity.\n\n");

}//show the instruction

double surface_area(double r, double h)
{
 double area;
 area=2*M_PI*r*h+M_PI*r*r;

 return area;
}//calculate the surface area
 
 
