/*
* Program Name: Lab 12
* Author's Name: Ayden Hession
* Class Day & Time: 3-5 PM
* Description: First the code counts the byte size of the file, and then prints it
in stdout
* it does this from start and from the 50th point
*
* next the code duplicates the code from result.txt into new.txt and flips the
characters case type
* This hurts my eyes to read
*/
#include <stdio.h>
#include <ctype.h>
int main()
{
FILE *result, *new;
result = fopen("result.txt", "r"); //open file as read file
//checking file byte size with this
fseek(result, 0, SEEK_END);
int bytes = ftell(result);
printf("%d\n\n", bytes);
fseek(result, 50, SEEK_CUR); //checking from 50th position to end
bytes = ftell(result);
printf("%d", bytes);
fclose(result);
//reopening for "r+" didn't need this step, but helped when debugging my code
result = fopen("result.txt", "r+");
new = fopen("new.txt", "w");
int c;
int count = 0; //counts the lowercase characters
while ((c = fgetc(result)) != EOF) //checks every position in
{
if (isupper(c)) //if/esle if changed the alphabet case
{
c = tolower(c);
}
else if (islower(c))
{
count++; //if it is lowercase then count increases
c = toupper(c);
}
fputc(c, new); //places the characters in the
}
fprintf(result, "\n\nThe number of lowercase characters are %d", count);
//adds this to bottom of result.txt
//closing files
fclose(result);
fclose(new);
return 0;
}