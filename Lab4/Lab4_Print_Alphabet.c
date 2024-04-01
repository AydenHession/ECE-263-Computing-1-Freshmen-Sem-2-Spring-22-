/*
* Program Name: Lab 4, Part A
* Author's Name: Ayden Hession
* Class Day & Time: Friday 3-5
* Program iterates through a-z
*/
#include <stdio.h>
int main()
{
char JuiceBox = 'a'; //initialize our first lowercase character
while (JuiceBox <= 'z') //ends after z
{
printf("%c\n", JuiceBox);
JuiceBox += 1; //iterates through
}
return 0;
}
