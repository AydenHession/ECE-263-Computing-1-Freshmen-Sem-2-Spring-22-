/*
* Program Name: Lab 8
* Author's Name: Ayden Hession
* Class Day & Time: Friday 3-5 PM
* Description: 3 different functions isVowel(), mystrcat(), and changStrCase()
* isVowel() returns 1 if there is a lowercase vowel in the string
* mystrcat() concatenates two strings
* changeStrCase() changes all letter capitalization to the opposite type
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int isVowel(char* str);
void changeStrCase(char* str);
void mystrcat(char* str1, char* str2);
int main(void)
{
int areThereVowels; //to check if the vowel command is working
char string1[] = "HBAt%nKihn!!"; //original string
char string2[] = "Hello:D"; //for concatination
areThereVowels = isVowel(&string1); //runs through the vowel funcion
printf("Are there vowels?\n");
printf("%d\n", areThereVowels);
printf("what is the original string?\n");
printf("%s\n", string1);
changeStrCase(&string1); //calls the function to change the string
capitalization
printf("what is the string with a changed case?\n");
printf("%s\n", string1);
mystrcat(&string1, &string2); //concatenates the changed string1 and string2
printf("what's the concatenated string?\n");
printf("%s\n", string1);
}
int isVowel(char* str)
{
for (int i = 0; str[i] != '\0'; i++) //runs through entire loop
{
if (isalpha(str[i]))
{
if (islower(str[i])) //returns 1 if there is a lowercase vowel
{
return 1;
}
}
}
return 0;
}
void changeStrCase(char* str)
{
int i = 0;
while (str[i] != '\0') //tbh, i hate while loops, idk why i used one. but
this goes through all string values
{
if (isalpha(str[i])) //checks for alphabet
{
if (isupper(str[i]))
{
str[i] = tolower(str[i]); //changes upper to lower
}
else
{
str[i] = toupper(str[i]); //changes lower to upper
}
}
i++;
}
}
void mystrcat(char* str1, char* str2)
{
char temp[] = ""; //temp string to make str1 at end
int len1 = strlen(str1) -1; //length of str1, not including the '\0' cause
unnecessary
int len2 = strlen(str2)-1; //length of str2, ommiting '\0'
for (int i = 0; i <= len1; i++) //starts parsing through str1 adding all
characters to the temp string
{
temp[i] = str1[i];
}
for (int j = len1; j <= (len1 + len2); j++) //startings at the length of
string one, so the index value after adding all the string values gets added
{
temp[j] = str2[j]; //adds all str2 values to temp
}
for (int q = 0; q < strlen(temp); q++) //this iterates through all the temp
string values and sets the str1 values to them with pointers
{
*(p + q) = temp[q];
}
}
