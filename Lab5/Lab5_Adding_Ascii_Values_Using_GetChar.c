/*
* Program Name: Lab 5 Part 2
* Author's Name: Ayden Hession
* Class Day & Time: Friday 3-5 PM
* Description: program takes user input using getchar()
* Totals up the ascii values of all inputs
* totals up the number of digits and upper case letters
* an adds total number of entrees
*/
#include <stdio.h>
#include <ctype.h>
int main()
{
char ch;
int Asum = 0; //ascii input sum
int Utot = 0; //Upper case letter total
int Dtot = 0; //Number/digit total
int Ctot = 0; //number of characters
printf("Input a character\n");
ch = getchar();
putchar(ch);
printf("\n"); // makes output more readable
while (ch != 'S')
{
if (isalnum(ch)) //checks for if it is an alphabet or number
{
if (isalpha(ch)) //checks if strictly alphabet
{
if (isupper(ch)) //checks if upper case alphabet letter
{
Utot += 1;
}
}
else //if number, the number of digits increases
{
Dtot += 1;
}
}
if (ch == '\n') //makes sure pressing return doesn't add to the input to
charcter total
{
Ctot -= 1;
printf("Input a character\n"); //asks for input after user presses
enter
}
Ctot += 1;
Asum = Asum + ch;
ch = getchar(); //gets next character entry
if (ch != '\n') //makes sure it doesn't display two empty '\n' inputs
{
putchar(ch);
printf("\n");
}
}
//accounts for 'S' character in the ascii sum and the total characters and
uppercase letters
Asum = Asum + ch;
Ctot += 1;
Utot += 1;
//displaying out put
printf("The Number of inputs was %d\n", Ctot);
printf("The number of upper case was %d\n", Utot);
printf("The number of Digits entered was %d\n", Dtot);
printf("The sum of all ascii values was %d\n", Asum);
return 0;
}
