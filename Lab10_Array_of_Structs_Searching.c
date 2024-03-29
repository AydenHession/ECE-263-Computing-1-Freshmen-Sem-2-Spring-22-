/*
* Program Name: Lab 10, Question 2
* Author's Name: Ayden Hession
* Class Day & Time: 3-5 PM, Friday
* Description: A struct named "team" is intialized
* 10 teams with their lose and win counts are added
* A
*/
#include <stdio.h>
#include <string.h>
struct team
{
char name[20];
int wins;
int losses;
};
int main()
{
//initializing an array of teams
struct team teams[10] = {
{"Apples", 10, 3},
{"Baseballs", 12, 4},
{"JuiceBox", 13, 4},
{"Stinky", 12, 3},
{"EpicStatus", 23, 0},
{"DogStatus", 0, 23},
{"Smelly", 4, 7},
{"Jacob", 3, 5},
{"London", 6, 2},
{"Andrea", 13, 5}
};
int topWin = 0; // used to store the index value of the team with the most
wins
for (int i = 1; i < 10; i++)
{
if (teams[i].wins > teams[topWin].wins) //if statement checks if next
team in line compares to the team with the current most wins. if they have more
wins then the index of TopWin is set to the i value
{
topWin = i;
}
}
printf("The team with the most wins is %s with %d wins", teams[topWin].name,
teams[topWin].wins);
return 0;
}
