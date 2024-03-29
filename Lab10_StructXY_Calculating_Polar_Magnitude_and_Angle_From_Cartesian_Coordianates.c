/*
* Project Name: Lab 10, part 1 a and b
* AUthor's Name: Ayden Hession
* Class Day and Time: 3-5 PM
* Description: two structs are initialized, both have variables for (x, y)
cartesian coordinates
* struct coord, is called twice, the two points are then ran through mid function
to find the midpoint of the two points
* struct com is used to find a point and the coordinate is put through mag and
angle to find the polar values of the cartesian coordinate.
* all these are then displayed for your veiwing pleasure :D
*/
#include <stdio.h>
#include <math.h>
void mid(struct coord p1, struct coord p2);
double mag(struct com z);
double angle(struct com z);
struct coord
{
int x;
int y;
};
struct com
{
int x;
int y;
};
int main()
{
//initializing points
struct coord point1;
struct coord point2;
struct com point3;
//obtaining values from user
printf("What are the values for the first point (x, y)?\n");
scanf("%d %d", &point1.x, &point1.y);
printf("\nWhat are the values for the second point (x, y)?\n");
scanf("%d %d", &point2.x, &point2.y);
mid(point1, point2); //calling midpoint function which has printf in it
printf("\nNow what would you like to be the points (x, y) for the next
point?\n");
scanf("%d %d", &point3.x, &point3.y);
printf("\nThe magnitude and angle(rad) in (r, theta)\n");
printf("(%.2lf, %.4lf)", mag(point3), angle(point3)); //displays the
magnitude and angle of the coordinates
}
void mid(struct coord p1, struct coord p2)
{
float x, y;
//have to cast to float, other wise decimal values not included
x = (float)(p1.x + p2.x) / 2;