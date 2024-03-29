/*
* Program Name: Lab 1
* Author's Name: Ayden Hession
* Class Day & Time: Friday 3-5 P.M.
* Description: Program takes user input of dimensions around
* a floor of a house to determine the cost of carpeting on floor
*/
#include <stdio.h>
int main(void)
{
//initializing variables
//dimensions/independent variables
float l;
float w;
float A1;
float B1;
float C1;
float h;
float s;
float carpetcost;
//combination/dependent variables
float den;
float garden;
float bathroom;
float area;
float carpetarea;
float totalcost;
//the following are getting user input's for the independent variables
//getting the carpetcost per sqft
printf("What is the cost per square foot of carpet?");
scanf("%f", &carpetcost);
printf("\nThe carpet cost has been set to %f\n\n", carpetcost);
//getting floor length and width and calculating the floor's area
printf("What is the length and width of the entire floor?\n");
scanf("%f %f", &l, &w);
area = l * w;
printf("\nThe area of the entire floor is %f\n\n", area);
//getting bathroom's dimensions and its area
printf("What are the floor dimensions of the bathroom?\n");
scanf("%f %f", &A1, &B1);
bathroom = A1 * B1;
printf("\nThe area of the bathroom is %f\n\n", bathroom);
//getting height and base of den and finding the den's floor area
printf("What is the Den's floor base and height dimensions?\n");
scanf("%f %f", &C1, &h);
den = C1 * h;
printf("\nThe area of the den is %f\n\n", den);
//geting the side length of the garden to find the garden's floor area
printf("What is the side length of the garden?\n");
scanf("%f", &s);
garden = ((3 * 1.728 * s * s) / 2);
printf("\nThe area of the garden is %f\n\n", garden);
//calculating the amount of the floor that is actually carpeted
carpetarea = area - (garden + den + bathroom);
//calculating the total cost of carpeting this area is
totalcost = carpetcost * carpetarea;
//printing out what the final cost is with the user's given dimensions
printf("The total cost of carpeting the floor is %f", totalcost);
return 0;