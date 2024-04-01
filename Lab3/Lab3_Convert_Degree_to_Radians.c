/*
* Program Name: Lab 3, 1a
* Author's Name: Ayden Hession
* Class Day & Time: Friday 3-5
* Program takes user input from 0-360, converts to radians,
then displays sin cos and tan
*/
#include <stdio.h>
#include <math.h>
int main()
{
int d;
float r, c, t, s;
printf("Input a degree value from 0-360\n"); //get user input
scanf("%d", &d);
r = .017453333 * d;
s = sin(r);
c = cos(r);
t = s / c; //tangent
printf("Given that degree, the value of sin cos and tan are %f %f %f", s, c,
t);
//return 0 to appease Valli :D
return 0;
}
