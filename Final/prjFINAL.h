//You can add any variable or function if deemed necessary in appropriate places
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _STUFF_
#define _STUFF_
struct f1player_se {
int ID;
int appDate;
int timeIn;
char PreviousTeam[30];
char PositionDesired[30];
int wins;
int QualificationPoint;
float RacePoint; // assume max racepoint: 1000
float averageskill_score;
struct f1player_se* next;
};
#endif
void fillData(struct f1player_se* X, int clockTime);
void printApps(struct f1player_se* X);
struct f1player_se* makeInitialList(int ct);
void fillData(struct f1player_se* node, int clockTime);
struct f1player_se* checkForApp(struct f1player_se* head, int x);
struct f1player_se* NewApplications(int clocktime);
