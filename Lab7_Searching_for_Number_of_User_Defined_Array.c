/*
* Program Name: Lab7
* Author's Name: Ayden Hession
* Class Day & Time: Friday 3-5 PM
* Description:
* readf() has user input values till 50 are inputted or till a number > 100 is
entered
* printArray() prints out the users inputed values in a four column output with 2
decimal places
* search() looks for the index of a value in the array, in this case is 6, if 6 is
not in the array then it returns -1
* countInRange() counts the number of elements that are in a given range
*/
#include <stdio.h>
int readf(float x[]);
void printArray(float x[], int size);
int search(float x[], int size, float n);
int countInRange(float x[], int size, float low, float high);
int main()
{
float arr[50];
int inputs; //for readf output
int s; // for search output
int c; //for count in range output
//calling functions
inputs = readf(arr);
//rest are put in terms of inputs for the length of the array because its
more efficient and avoids garbage values when printing.
printArray(arr, inputs);
s = search(arr, inputs, 6);
c = countInRange(arr, inputs, 1, 10);
printf("The search return the index of: %d\n", s);
printf("Values within the given range was: %d\n", c);
}
int readf(float x[])
{
float temp = 0; //this value will be set to x[i] as long as it is not over
100
int count = 0;
printf("Input values for the array\n"); //for readability when printed out
for (int i = 0; i < 50; i++)
{
scanf("%f", &temp);
if (temp > 100) //makes it so values over 100 are not included in the
array,
{
break;
}
x[i] = temp;
Aliana Binti Shahimi
should ask user to input n
Aliana Binti Shahimi
should ask user input for high and low
count++;
}
return count; //returns number of float values inputed
}
void printArray(float x[], int size)
{
int space = 0; // will be used to print in column format
printf("The Array x[] array is as follows."); //for readability when printed
out
for (int i = 0; i < size; i++)
{
if (space % 4 == 0) //drops column
{
printf("\n");
}
printf("%.2f ", x[i]); //print values with two decimal places
space++; //adds to the space to make sure after 4 values the print out
is in column format
}
printf("\n"); //for readability when printing
}
int search(float x[], int size, float n)
{
for (int i = 0; i < size; i++)
{
if (x[i] == n)
{
return i; //will return index location of value equal to n,
return exists the function
}
}
return -1; //if the whole array is parsed through w/o finding a value then
this will return -1
}
int countInRange(float x[], int size, float low, float high)
{
int count = 0;
for (int i = 0; i < size; i++)
{
if ((x[i] >= low) && (x[i] <= high)) //checks if number is in range
{
count += 1;
}
}
return count; //returns number of elements within the range
}