/*
* Program Name: Lab6 header
* Author's Name: Ayden Hession
* Class Day & Time: Friday 3-5 PM
* Description: three functions, minimum average and frequency
* Minimum returns the smallest number in the array
* Average returns the average of all the values
* Frequency returns the value that occurs the most often in the array
*/
#pragma once
int minimum(int aRR[], int size)
{
int mini = aRR[0]; //sets minimum value of first value
for (int n = 1; n < size; n++) //runs through all values
{
if (mini > aRR[n]) //if a value is less than the current min it is set
to min
{
mini = aRR[n];
}
}
return mini;
}
float average(int aRR[], int size)
{
//initialize variables
float avg;
float sum = 0;
for (int n = 0; n < size; n++) //runs through all array values
{
sum = sum + aRR[n]; //adds all values to the sum
}
avg = sum / size; //takes the sum and divides it by the array size to get the
average
return avg;
}
int frequency(int aRR[], int size)
{
//initialize variables
int freq;
int curr = aRR[0]; //most frequent number is set to first value
int tempN = 0; //counter for an array value
int overN = 1; //counter for overall value that has occured the most
for (int i = 0; i < size; i++) //runs through each point in the array
{
tempN = 0; // gets set to 0 everytime to be able to compare number of
times array element shows up
for (int j = 0; j < size; j++) //runs through array again to compare
current value to the other array values
{
if (aRR[i] == aRR[j]) //checks if value is equal to all array
values
{
tempN += 1; //temp counter increases when it finds a match
}
if (tempN > overN) //if temp counter is greatest then it occurs
the most often
{
overN = tempN; //counter mark is set to new amount
curr = aRR[i]; //current character is updated to the one
that has occured most often thus far
}
}
}
return curr;
}