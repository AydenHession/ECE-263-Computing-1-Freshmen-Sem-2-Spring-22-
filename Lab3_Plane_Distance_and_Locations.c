
*
* Program Name: Lab3, Part B
* Author's Name: Ayden Hession
* Class Day & Time: Friday 3-5
* This program takes the the orginal position of a plane and then
* the next position and then finds the distance travels
* it also finds the angle measurement of a right triangle by means of complex math
*/
#include <stdio.h>
#include <math.h>
int main()
{
float dtr = .017453333;
float AB, AE, DC; //side length equation
int a; // angle i need to solve for
float b, c; //30 and 60 angles to be converted to radians
float ca, cb, sa, sb; // sin and cos for both angles
float ta, tb; // tan values for
b = 60 * dtr;
c = 30 * dtr;
//sin and cos for 30 d angle
ca = cos(c);
sa = sin(c);
//sin and cos for 60 d angle
cb = cos(b);
sb = sin(b);
//tan for both angles
ta = (sa) / (ca);
tb = (sb) / (cb);
//calculating side lengths
AE = (2500) / (ta);
AB = (2500) / (tb);
//distance plane has traveled
DC = AE - AB;
//using complex math to find the angle of a
a = 180 - 90 - 60;
//display results
printf("Distance plane has traveled is %f, the angle is %d", DC, a);
//return 0 to make valli happy
return 0;
}
