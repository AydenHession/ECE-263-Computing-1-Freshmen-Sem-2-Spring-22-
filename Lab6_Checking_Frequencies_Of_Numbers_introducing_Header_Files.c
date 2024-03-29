/*
* Program Name: Lab6 main function
* Author's Name: Ayden Hession
* Class Day & Time: Friday 3-5 PM
* Description: returns minimum average and frequency
* Has user give an array of numbers, values of 0 and over 1000
* loop ends once 30 values have been put in
*/
#include <stdio.h>
#include "juiceboxesayden.h" //imports the header file
int main()
{
int JuiceBoxes[30]; // array of 30
int num; //value of user
int min;
int freq;
float avg;
int i = 0; //terminates loop
printf("Input 30 values for the array, don't go over 1000, don't input 0\n");
while ((scanf("%d", &num)) == 1)
{
if (num > 1000) //doesn't allow for value over 1000, lets user place
value for this point in array again
{
continue;
}
if (num == 0) //ends loop if value set to 0, value will still be set to
0
{
break;
}
JuiceBoxes[i] = num; //sets input value of user to spot in array
i++;
if (i >= 30) //well end loop after 30 elements have been inputed
{
break;
}
printf("Give more inputs for the array\n");
}
//calling functions from header file
//these values are set to i, so that when the loop has an input value that is
set as 0 the output doesn't return garbage values
min = minimum(JuiceBoxes, i);
freq = frequency(JuiceBoxes, i);
avg = average(JuiceBoxes, i);
//displaying the outputs
printf("Minimum is %d\n", min);
printf("Most frequent number is %d\n", freq);
printf("Average value is %f\n", avg);
}
