#include <stdio.h>
#include <stdlib.h>
#include"prj.h"
char* team[6] = { "Mercedes", "RedBull", "Mclaren", "Alpine", "Haas", "Porsche" };
char* pos[3] = { "Main_Driver", "Substitute_Driver", "Test_Driver" };
void fillData(struct f1player_se* X, int clockTime)
{
int i;
int numb;
static int val = 10001;
X->ID = val;
val += 1 + (rand() % 7);
X->appDate = clockTime;
X->timeIn = 0;
numb = rand() % 3;
strcpy(X->PositionDesired, pos[numb]);
numb = rand() % 6;
strcpy(X->PreviousTeam, team[numb]);
X->averageskill_score = (rand() % 11);//average skill score between 0-10
X->wins = (rand() % 50);
X->QualificationPoint = (rand() % 250);
X->RacePoint = (rand() % 1000);
X->next = NULL;
}
struct f1player_se* checkForApp(struct f1player_se* head, int x) {
while (head != NULL)
{
if (head->ID == x)
break;
head = head->next;
}
return head;
}
struct f1player_se* makeInitialList(int clocktime)
{
struct f1player_se* H;
struct f1player_se* ptr;
struct f1player_se* last;
int i;
H = (struct f1player_se*)malloc(sizeof(struct f1player_se));
fillData(H, clocktime);
last = H;
for (i = 0; i < 20; i++)
{
ptr = (struct f1player_se*)malloc(sizeof(struct f1player_se));
fillData(ptr, clocktime);
last->next = ptr;
last = last->next;
}
return H;
}
struct f1player_se* NewApplications(int clocktime)
{
struct f1player_se* head;
struct f1player_se* ptr, * prev;
int num = 3;
int i;
num = num + (rand() % 5);
head = (struct f1player_se*)malloc(sizeof(struct f1player_se));
fillData(head, clocktime);
prev = head;
for (i = 0; i < num - 1; i++)
{
ptr = (struct f1player_se*)malloc(sizeof(struct f1player_se));
fillData(ptr, clocktime);
prev->next = ptr;
prev = ptr;
}
return head;
}
void printApps(struct f1player_se* X)
{
struct f1player_se* ptr;
ptr = X;
printf("%10s %6s %6s %30s %10s\n", "pointer", "Date", "ID",
"positionDesired", "nextApp");
while (ptr != NULL)
{
printf("%10d %6d %6d %30s %10d\n", ptr, ptr->appDate, ptr->ID, ptr-
>PositionDesired, ptr->next);
ptr = ptr->next;
}
}