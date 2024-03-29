/*
* Project Name: Lab 11
* Author's Name: Ayden Hession
* Class Day & Time: 3-5 PM
* Description: obtains a number from the user representative of the number of nodes
* Then it prompts the user to input a GPA, and checks through the list with search
function
*/
#include <stdio.h>
#include <stdlib.h>
struct student
{
int ID;
float gpa;
int credit;
char dept[5];
struct student* next;
};
char* pos[5] = { "ECE","ME","BME","AI","CS" };
void fillData(struct student* X);
void search(struct student* X, float gp);
int main()
{
int n;
float SGPA;
struct student* HEAD, * CURRENT, * TEMP; //variables to help fill aray
HEAD = (struct student*)malloc(sizeof(struct student));
printf("Enter the number of nodes.\n");
scanf("%d", &n);
printf("\n\n");
printf("Enter the GPA you want to search for.\n");
scanf("%f", &SGPA);
for (int i = 0; i < n; i++) //for loops iterates from the n term that the
user
{
CURRENT = (struct student*)malloc(sizeof(struct student));
fillData(CURRENT);
if (i == 0)
{
TEMP = CURRENT;
HEAD = TEMP;
}
else
{
TEMP->next = CURRENT; //points to next struct
TEMP = CURRENT; //updates front number
}
}
TEMP->next = NULL; //end value set to Null
TEMP = HEAD; //head struct stays in front for ease-ability
search(HEAD, SGPA);
}
void fillData(struct student* X) //Valli gave us this, bless her soul
{
int i;
int numb;
float gp;
int credit;
X->ID = 100 * (rand() % 20);
X->credit = rand() % 10;
gp = 4 * (float)rand() / RAND_MAX;
X->gpa = gp;
numb = rand() % 5;
strcpy(X->dept, pos[numb]);
X->next = NULL;
}
void search(struct student* X, float gp)
{
struct student* HEAD, * CURRENT;
HEAD = X; //this whole step is pretty useless, but i cannot comprehend the
linked list without the Word "head" rn
CURRENT = HEAD;
int i = 1;
while (CURRENT != NULL) //will stop once null, works in tandem with L95,
Current = Current -> next;, to iterate and check all gpa values in list
{
if (CURRENT->gpa == gp)
{
printf("\nThe Matching Gpa is in Node #%d\n", i);
return; //breaks out of function, so second print function
doesn't execute as well.
}
CURRENT = CURRENT->next; //points to next point in the list
i++;
}
printf("\nThe was no matching GPA in the linked list for your input...
SMelly\n"); //tells user they stink
}