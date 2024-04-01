//include necessary library function
//adding more than needed at start to ensure it works
#include "prj.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
char* posi[3] = { "Main_Driver", "Substitute_Driver", "Test_Driver" };
void swap(struct f1player_se* ptr, struct f1player_se* ptrn);
struct f1player_se* sortByWins(struct f1player_se* head)
{
struct f1player_se* i, * j;
i = head;
j = head->next;
for (i = head; i != NULL; i = i->next) //runs through the outside
{
for (j = i->next; j != NULL; j = j->next)
{
if ((i->wins) < (j->wins))
{
swap(i, j);
}
}
}
head = i;
return head;
}
void print_sameRacePoint(struct f1player_se* head)
{
struct f1player_se* i, * j;
struct f1player_se* good; //will return nothing if there is a working
function
struct f1player_se* nullification = NULL; //way to return NULLL
int NullOrNot = 0;
i = head;
j = head->next;
for (i = head; i != NULL; i = i->next)
{
for (j = i->next; j != NULL; j = j->next)
{
if ((i->RacePoint) == (j->RacePoint))
{
printf("Driver-ID appDate Time-In Previous-Team
Position-Desired Wins Qualification-Point Race-Point\n");
printf("===========================================================================
===============================\n");
printf("%-12d%-10d%-10d%-16s%-19s%-7d%-22d%.2f\n", i->ID,
i->appDate, i->timeIn, i->PreviousTeam, i->PositionDesired, i->wins, i-
>QualificationPoint, i->RacePoint);
printf("%-12d%-10d%-10d%-16s%-19s%-7d%-22d%.2f\n", j->ID,
j->appDate, j->timeIn, j->PreviousTeam, j->PositionDesired, j->wins, j-
>QualificationPoint, j->RacePoint);
}
}
}
if (NullOrNot == 1)
{
printf("");
}
else
{
printf("NULL\n");
}
}
struct f1player_se* deleteApplication(struct f1player_se* head, struct f1player_se*
to_be_gone) //given by valli, bless her soul
{
while (head != NULL)
{
if (head->next == to_be_gone)
{
head->next = head->next->next;
free(to_be_gone);
}
}
return head;
}
struct f1player_se* hiring(struct f1player_se* head, char* position)
{
//when hiring we are assuming the list is already sorted in the formate that
we want it to be.
struct f1player_se* current;
current = head;
if (strcmp(position, "Main_Driver")) //making sure that their avgskillscore
value matches with the position they want or they will be skipped.
{
while (current != head)
{
if ((strcmp(current->PositionDesired, position)) && ((current-
>averageskill_score) > 7))
{
deleteApplication(head, current);
}
}
}
else if (strcmp(position, "Substitute_Driver"))
{
while (current != head)
{
if ((strcmp(current->PositionDesired, position)) && ((current-
>averageskill_score) <= 7 ) && ((current->averageskill_score) >4))
{
deleteApplication(head, current);
}
}
}
else if (strcmp(position, "Test_Driver"))
{
while (current != head)
{
if ((strcmp(current->PositionDesired, position)) && ((current-
>averageskill_score) >= 1) && ((current->averageskill_score) <= 4))
{
deleteApplication(head, current);
}
}
}
return head;
}
struct f1player_se* process(struct f1player_se* head, int* clockTime)
{
struct f1player_se* current;
struct f1player_se* NEWlist;
current = head;
//increment clock time
//working in steps to ensure everything works, next two loops could be one
single loop.
while (current != NULL) //increment all the times
{
current->timeIn = ((current->timeIn) + (*clockTime +1));
current= current->next;
}
current = head;
while (current != NULL) //get rid of any apps two or more years.
{
if ((current->timeIn) >= 2)
{
deleteApplication(head, current);
}
current = current->next;
}
current = head;
hiring(head, posi[0]);
hiring(head, posi[1]);
hiring(head, posi[2]);
NEWlist = NewApplications(clockTime);
struct f1player_se* tempNEW;
tempNEW = NEWlist;
do //with the do-while we can get to the end of the list where the current
will equal NULL, and then begin adding onto the list.
{
if (current == NULL)//will check to make sure we are at the end of the
loop
{
while (NEWlist != NULL) //will continue adding until the second
loop is NULL
{
current = NEWlist; //adds to the original list
current = current->next; // will always end up pointing to
NULL character
NEWlist = NEWlist->next; //iterates the loop
}
}
current = current->next; //will end up pointing at a NULL character and
exiting the loop
} while (current != NULL);
head = current;
return head;
}
void printFormatted(struct f1player_se* head)
{
struct f1player_se* current;
current = head;
printf("Driver-ID appDate Time-In Previous-Team Position-Desired
Wins Qualification-Point Race-Point\n");
printf("===========================================================================
===============================\n");
while (current != NULL) //running through linked list
{
printf("%-12d%-10d%-10d%-16s%-19s%-7d%-22d%.2f\n", current->ID,
current->appDate, current->timeIn, current->PreviousTeam, current->PositionDesired,
current->wins, current->QualificationPoint, current->RacePoint);
current = current->next;
}
}
void analyzeApplicantList(struct f1player_se* head)
{
struct f1player_se* current;
current = head;
/*selected groups, array set to 60 elements, doens't need this many since
only 20 drivers per year are created with IntialList()
but is to make sure it works before making it efficient as possible*/
struct f1player_se* group1[60];
struct f1player_se* group2[60];
struct f1player_se* group3[60];
group1[60]= malloc(sizeof(struct f1player_se));
group2[60] = malloc(sizeof(struct f1player_se));
group3[60] = malloc(sizeof(struct f1player_se));
/*selecting groups based on them being on same team, those not on a team are
not added to list
while numerically they are on a same team in the code, they woulnt not have
worked together in a real world setting.*/
struct f1player_se* Mercedes[60];
struct f1player_se* RedBull[60];
struct f1player_se* Mclaren[60];
struct f1player_se* Alpine[60];
struct f1player_se* Haas[60];
struct f1player_se* Porsche[60];
Mercedes[60] = malloc(sizeof(struct f1player_se));
RedBull[60] = malloc(sizeof(struct f1player_se));
Mclaren[60] = malloc(sizeof(struct f1player_se));
Alpine[60] = malloc(sizeof(struct f1player_se));
Haas[60] = malloc(sizeof(struct f1player_se));
Porsche[60] = malloc(sizeof(struct f1player_se));
int hun = 100;
int zero = 0;
//does part 1 of anaylze applications, displays there ability to be main sub
or test with 100 being yes and 0 being no
printf("Driver-ID AverageSkill-Score Test Sub Main\n");
printf("=============================================================\n");
while (current != NULL)
{
if ((current->averageskill_score) > 7)
{
printf("%-12d%-21.2f%-7d%-6d%d\n", current->ID, current-
>averageskill_score, hun, hun, hun); //player has 100 ability/chance to be apart of
sub, main, or test
}
else if ((current->averageskill_score) > 4)
{
printf("%-12d%-21.2f%-7d%-6d%d\n", current->ID, current-
>averageskill_score, hun, hun, zero); //player is 0% likely to be main, but can be
sub or test
}
else if ((current->averageskill_score) > 1)
{
printf("%-12d%-21.2f%-7d%-6d%d\n", current->ID, current-
>averageskill_score, hun,zero, zero); //only test
}
else if ((current->averageskill_score) == 0) //mans stinks, banished
{
deleteApplication(head, current);
}
current = current->next;
}
current = head;
int ME = 0;
int RE = 0;
int MC = 0;
int AL = 0;
int HA = 0;
int PO = 0;
//after current is reset, next loop checks second condition, prints the
players that belond to the same team.
while (current != NULL)
{
if (strcmp(current->PreviousTeam, "Mercedes")) //mercedes
{
Mercedes[ME] = current;
ME++;
}
else if (strcmp(current->PreviousTeam,"RedBull"))//redbull
{
RedBull[RE] = current;
RE++;
}
else if (strcmp(current->PreviousTeam, "Mclaren"))//Mclaren
{
Mclaren[MC] = current;
MC++;
}
else if (strcmp(current->PreviousTeam, "Alpine"))//alpin
{
Alpine[AL] = current;
AL++;
}
else if (strcmp(current->PreviousTeam, "Haas"))//haas
{
Haas[HA] = current;
HA++;
}
else if (strcmp(current->PreviousTeam, "Porsche"))//porsche
{
Porsche[PO] = current;
PO++;
}
current = current->next;
}
/*Here on its just copy and paste of the same print loops over and over again
printing out the players */
/*this statement makes sure there is at leaste two people of same previous
team
if not, then there is no point in printing the team because this driver would
never have driven with anyone else
also this avoids trying to print someone if no one has been on this team in
the past, avoiding errors*/
if (strcmp(Mercedes[1]->PreviousTeam, "Mercedes"))
{
printf("\n\nPlayers with Past team Mercedes\n");
printf("Driver-ID appDate Time-In Previous-Team Position-
Desired Wins Qualification-Point Race-Point\n");
printf("===========================================================================
===============================\n");
for (int n = 0; n <= ME; n++)
{
printf("%-12d%-10d%-10d%-16s%-19s%-7d%-22d%.2f\n", Mercedes[n]-
>ID, Mercedes[n]->appDate, Mercedes[n]->timeIn, Mercedes[n]->PreviousTeam,
Mercedes[n]->PositionDesired, Mercedes[n]->wins, Mercedes[n]->QualificationPoint,
Mercedes[n]->RacePoint);
}
}
if (strcmp(RedBull[1]->PreviousTeam, "RedBull"))
{
printf("\n\nPlayers with Past team Redbull\n");
printf("Driver-ID appDate Time-In Previous-Team Position-
Desired Wins Qualification-Point Race-Point\n");
printf("===========================================================================
===============================\n");
for (int n = 0; n <= RE; n++)
{
printf("%-12d%-10d%-10d%-16s%-19s%-7d%-22d%.2f\n", RedBull[n]-
>ID, RedBull[n]->appDate, RedBull[n]->timeIn, RedBull[n]->PreviousTeam, RedBull[n]-
>PositionDesired, RedBull[n]->wins, RedBull[n]->QualificationPoint, RedBull[n]-
>RacePoint);
}
}
if (strcmp(Mclaren[1]->PreviousTeam, "Mclaren"))
{
printf("\n\nPlayers with Past team Mclaren\n");
printf("Driver-ID appDate Time-In Previous-Team Position-
Desired Wins Qualification-Point Race-Point\n");
printf("===========================================================================
===============================\n");
for (int n = 0; n <= MC; n++)
{
printf("%-12d%-10d%-10d%-16s%-19s%-7d%-22d%.2f\n", Mclaren[n]-
>ID, Mclaren[n]->appDate, Mclaren[n]->timeIn, Mclaren[n]->PreviousTeam, Mclaren[n]-
>PositionDesired, Mclaren[n]->wins, Mclaren[n]->QualificationPoint, Mclaren[n]-
>RacePoint);
}
}
if (strcmp(Alpine[1]->PreviousTeam, "Alpine"))
{
printf("\n\nPlayers with Past team Alpine\n");
printf("Driver-ID appDate Time-In Previous-Team Position-
Desired Wins Qualification-Point Race-Point\n");
printf("===========================================================================
===============================\n");
for (int n = 0; n <= AL; n++)
{
printf("%-12d%-10d%-10d%-16s%-19s%-7d%-22d%.2f\n", Alpine[n]->ID,
Alpine[n]->appDate, Alpine[n]->timeIn, Alpine[n]->PreviousTeam, Alpine[n]-
>PositionDesired, Alpine[n]->wins, Alpine[n]->QualificationPoint, Alpine[n]-
>RacePoint);
}
}
if (strcmp(Haas[1]->PreviousTeam, "Haas"))
{
printf("\n\nPlayers with Past team Mclaren\n");
printf("Driver-ID appDate Time-In Previous-Team Position-
Desired Wins Qualification-Point Race-Point\n");
printf("===========================================================================
===============================\n");
for (int n = 0; n <= HA; n++)
{
printf("%-12d%-10d%-10d%-16s%-19s%-7d%-22d%.2f\n", Haas[n]->ID,
Haas[n]->appDate, Haas[n]->timeIn, Haas[n]->PreviousTeam, Haas[n]->PositionDesired,
Haas[n]->wins, Haas[n]->QualificationPoint, Haas[n]->RacePoint);
}
}
if (strcmp(Porsche[1]->PreviousTeam, "Porsche"))
{
printf("\n\nPlayers with Past team Mclaren\n");
printf("Driver-ID appDate Time-In Previous-Team Position-
Desired Wins Qualification-Point Race-Point\n");
printf("===========================================================================
===============================\n");
for (int n = 0; n <= PO; n++)
{
printf("%-12d%-10d%-10d%-16s%-19s%-7d%-22d%.2f\n", Porsche[n]-
>ID, Porsche[n]->appDate, Porsche[n]->timeIn, Porsche[n]->PreviousTeam, Porsche[n]-
>PositionDesired, Porsche[n]->wins, Porsche[n]->QualificationPoint, Porsche[n]-
>RacePoint);
}
}
/* A Transition from 2 to 3 of this function*/
current = head;
int i = 0;
int j = 0;
int k = 0;
//after reseting current to the start, next loop groups the players of
similar racepoints
while (current != NULL) //throwing nodes into different arrays
{
if ((current->RacePoint) >= 750)
{
group1[i] = current;
i++;
}
else if (((current->RacePoint) >= 500) && ((current->RacePoint)<750))
{
group2[j] = current;
j++;
}
else if ((current->RacePoint) <500)
{
group3[k] = current;
k++;
}
current = current->next;
}
printf("Players with 750 - 1000 Racepoint: Group 1\n");
printf("Driver-ID appDate Time-In Previous-Team Position-Desired
Wins Qualification-Point Race-Point\n");
printf("===========================================================================
===============================\n");
for (int n = 0; n <= i; n++)
{
printf("%-12d%-10d%-10d%-16s%-19s%-7d%-22d%.2f\n", group1[n]->ID,
group1[n]->appDate, group1[n]->timeIn, group1[n]->PreviousTeam, group1[n]-
>PositionDesired, group1[n]->wins, group1[n]->QualificationPoint, group1[n]-
>RacePoint);
}
printf("\n\nPlayers with 500-749 Racepoint: Group 2\n");
printf("Driver-ID appDate Time-In Previous-Team Position-Desired
Wins Qualification-Point Race-Point\n");
printf("===========================================================================
===============================\n");
for (int n = 0; n <= j; n++)
{
printf("%-12d%-10d%-10d%-16s%-19s%-7d%-22d%.2f\n", group2[n]->ID,
group2[n]->appDate, group2[n]->timeIn, group2[n]->PreviousTeam, group2[n]-
>PositionDesired, group2[n]->wins, group2[n]->QualificationPoint, group2[n]-
>RacePoint);
}
printf("\n\nPlayers with 0-500 Racepoint: Group 3\n");
printf("Driver-ID appDate Time-In Previous-Team Position-Desired
Wins Qualification-Point Race-Point\n");
printf("===========================================================================
===============================\n");
for (int n = 0; n <= k; n++)
{
printf("%-12d%-10d%-10d%-16s%-19s%-7d%-22d%.2f\n", group3[n]->ID,
group3[n]->appDate, group3[n]->timeIn, group3[n]->PreviousTeam, group3[n]-
>PositionDesired, group3[n]->wins, group3[n]->QualificationPoint, group3[n]-
>RacePoint);
}
}
void terminateAndWrite(struct f1player_se* head)
{
struct f1player_se* current;
current = head;
FILE* list;
list = fopen("text.txt", "w+");
fprintf(list, "Driver-ID appDate Time-In Previous-Team Position-
Desired Wins Qualification-Point Race-Point\n");
fprintf(list,
"==================================================================================
========================\n");
while (current != NULL) //loop runs though every node and prints it
{
fprintf(list, "%-12d%-10d%-10d%-16s%-19s%-7d%-22d%.2f\n", current->ID,
current->appDate, current->timeIn, current->PreviousTeam, current->PositionDesired,
current->wins, current->QualificationPoint, current->RacePoint);
current = current->next;
}
fclose(list); //close file
free(head); //clear memory
exit(0);
}
void swap(struct f1player_se* ptr, struct f1player_se* ptrn)
{
struct f1player_se* temp;
temp = ptr;
ptr = ptrn;
ptrn = temp;
}