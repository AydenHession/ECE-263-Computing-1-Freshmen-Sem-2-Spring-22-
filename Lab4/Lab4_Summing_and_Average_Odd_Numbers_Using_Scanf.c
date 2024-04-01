/*
* Program Name: Lab 4, Part B
* Author's Name: Ayden Hession
* Class Day & Time: Friday 3-5
* Program computes the sum of first n odd numbers
* determins average in two different ways
*/
#include <stdio.h>
int main()
{
//initializing all variables
int n;
int i = 1;
int sum = 0;
int counter = 1;
float avg;
printf("Give the number of odd values you want\n");
scanf("%d", &n); //geting user input
//while loop adds numbers odd numbers starting with 1 going to n values
while (i <= n)
{
sum = sum + counter;
counter += 2;
i++;
}
//calculating the average
avg = sum / n;
printf("Sum of odd first %d odd numbers is %d, there average is %f\n", n,
sum, avg);
//reseting variables to show the seconds approach
sum = 0;
counter = 1;
avg = 0.0;
printf("give the number of odd values a second time\n");
scanf("%d", &n);
i = n;
//same loop as before but now counts down to 1 (until all n odd values are
used)
while (i >= 1)
{
sum = sum + counter;
counter += 2;
i--;
}
avg = sum / n; //calculate average of second method
printf("Sum of odd first %d odd numbers is %d, there average is %f for second
n\n", n, sum, avg);
}
