/*
* Program Name: Lab 5 Part 1
* Author's Name: Ayden Hession
* Class Day & Time: Friday 3-5PM
* Description: make a V using the * symbol
*/
#include <stdio.h>
int main()
{
for (int i = 1; i <= 5; i++) //loop for the 1 to 5 columns left and right
{
for (int j = 1; j <= 3; j++) //loop for the first three columns
{
if (j == i)// will add a * then i = j, so the first point in first
column, second column for second row
{
printf("*");
}
else
{
printf(" "); //adds blanks where i != j
}
}
for (int k = 5; k >= 4; k--) //last two columns
{
if (k == (i + 3))//starts at fourth cloumn since i +3
{
printf("*"); // adds when k = i+3, so in first row after next space
has been placed
}
else
{
printf(" ");
}
}
printf("\n");// returns down to start the next row
}
return 0;
}
