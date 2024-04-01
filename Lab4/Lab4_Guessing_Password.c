/*
* Program Name: Lab4, Part C
* Author's Name: Ayden Hession
* Class Day & Time: Friday 3-5
* This program has a user make a guess
* if their guess matches the secret value then it displays
* a good message
*/
#include <stdio.h>
int main()
{
int secret = 7;
int guess;
printf("please input a guess 1-10 \n");
scanf("%d", &guess);
while (secret != guess)
{
printf("Your guess is wrong, try again\n");
scanf("%d", &guess);
}
printf("You got it!!");
}
