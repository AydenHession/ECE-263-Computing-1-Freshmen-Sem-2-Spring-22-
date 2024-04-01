//include library functions necessary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include"prj.h"
#include "projstud.h"
void print_main_menu(); //this function will display the menu for the user which
will include the character and its associted function to execute. Based on the
character entered by the user, one of the seven functions will be executed
int main()
{
//initialize/modify any variable you think is necessary
int list_size;
int ct = 0;
char buffer[100], ch;
struct f1player_se* listptr, * pL;
int app_to_be_gone, code;
//this random number will help in assigning values to all the applicants,
i.e., information of the applicants are randomly assigned
printf("Enter a seed to the random number generator (i.e. an integer >0)\n");
gets(buffer);
srand(atoi(buffer));
listptr = makeInitialList(ct);
print_main_menu();
printf(">>>>> Enter a command/character \n");
gets(buffer);
char X = toupper(buffer[0]);
while (X != NULL)//fill the condition
{
print_main_menu();
printf(">>>>> Enter a command/character ");
gets(buffer);
X = toupper(buffer[0]);
switch (X)
{
case 'D':
//Delete Application from list
printFormatted(listptr);
printf(">>>>> Choose an Application ID to Delete\n");
app_to_be_gone = (int)atoi(gets(buffer));
pL = checkForApp(listptr, app_to_be_gone);
if (pL != NULL)
listptr = deleteApplication(listptr, pL);
else
printf("there is no application with application ID= %d\
n", app_to_be_gone);
break;
case 'H':
//Process function
listptr = process(listptr, &ct);
break;
//do for remaining function to associate character to function to
execute
case 'A':
//analyze applicant list
analyzeApplicantList(listptr);
break;
case 'P':
//print formated list
printFormatted(listptr);
break;
case 'S':
//sort by wins
sortByWins(listptr);
break;
case 'E':
//same winpoint printed
print_sameRacePoint(listptr);
break;
case 'T':
//terminate
terminateAndWrite(listptr);
exit(0);
return 0;
break;
}
}
}
//write code
void print_main_menu()
{
printf("Main Menu\n==================\nA: Analyze Applicant List\
nD: Delete Application\nP: Print Formated List\nH: Hire/Process List\nS: Sort By
Wins\nE: Equal RacePoints Printed\nT: Terminate and Write In File\
n==================\n\n");
}