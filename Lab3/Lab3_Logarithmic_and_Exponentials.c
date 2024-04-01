/*
* Program Name: Lab 3, 1a
* Author's Name: Ayden Hession
* Class Day & Time: Friday 3-5
* returns e^x given a user input of x between 1-5
* sum1 is the sum of the of e^x of first five sums of given e^x
* then computes sqrt(sum1), log(delta = sum1, and sum1^2
*/
#include <stdio.h>
#include <math.h>
int main()
{
float x;
float rt, lg, sq; //sqrt log and sum^2
float sum1; //value of exponent/sum thing
printf("Give a value of x for e^x\n");
//user input for x power
scanf("%f", &x);
//the big e^x to the fifth point
sum1 = 1 + ((x) / (1)) + ((x * x) / (1 * 2)) + ((x * x * x) / (1 * 2 * 3)) +
((x * x * x * x) / (1 * 2 * 3 * 4)) + ((x * x * x * x * x) / (1 * 2 * 3 * 4 * 5));
rt = sqrt(sum1); //sqrt of sum1
lg = log(sum1); //ln of sum1
sq = pow(sum1, 2);//sum^2
printf("sum1 = %f, sqrt(sum1) = %f, log(sum1) = %f, sum1^2 = %f", sum1, rt,
lg, sq);
//To appease valli i shall put return 0
return 0;
}
