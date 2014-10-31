//Author: Angela(Haowen) Zhou

#include<stdio.h>

int
main()
{
 int initial, fuel;
 double tax, total;
 
 printf("This program determines the total cost of owning a home for five" 
        " years.\nThe user will enter initial cost in whole dollars, annual" 
        " fuel costs in \nwhole dollars, and the annual tax rate as a real" 
        " number.\n");
 printf("Please enter the initial cost, fuel cost, and tax rate: ");
 scanf("%d%d%lf", &initial, &fuel, &tax);
 
 total= initial+ fuel*5 +(initial*tax)*5;
 
 printf("The total cost is $%.2lf.\n", total);
 
 return(0);
}//end of main

