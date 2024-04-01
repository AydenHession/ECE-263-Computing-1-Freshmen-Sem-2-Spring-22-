/*
* Project Name: Lab 9, Part 2
* Author's Name: Ayden Hession
* Class Day & Time: Friday 3-5 PM
* Description: Code gets a sentence from the user and then replaces the spaces with
'*'
* Them the code checks for the word "the" with that exact spelling and counts the
number of times it pops up
* The file description didn't ask to ensure the capital, just the all lowercase
version of "the"
*/
#include <stdio.h>
int main()
{
int count = 0;
char string[50];
printf("Type a sentence\n");
fgets(string, 50, stdin); //makes sure the person cannot put in a sentence
over 50 char
puts(string);
int i = 0;
while (string[i] != '\0') //loop replaces the spaces with * symbol
{
if (string[i] == ' ')
{
string[i] = '*';
}
i++;
}
puts(string);
i = 0;
while (string[i] != '\0') //this checks if "the" shows up in the string with
the lowercase spelling only
{
if (string[i] == 't') //if 't' shows up then will check the following
terms
{
if ((string[i + 1] == 'h') || (string[i + 2]))
{
count++;
}
}
i++;
}
printf("%d\n", count); //displays the number of "the" words in the sentence
}
